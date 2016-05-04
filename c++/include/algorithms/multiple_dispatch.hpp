#ifndef __algorithms_multiple_dispatch_hpp
#define __algorithms_multiple_dispatch_hpp

#include <iostream>

/*******************************************************************************

 multiple_dispatch.h

 Eli Bendersky's article on multiple dispatch in C++.

 http://eli.thegreenplace.net/2016/a-polyglots-guide-to-multiple-dispatch/

 ******************************************************************************/

// class prototypes / declarations
class Shape;
class Rectangle;
class Ellipse;

/*
  Shape

  Base class for all shapes. Uses multiple dispatch for computing intersections.
 */
class Shape {
 public:
  virtual std::string name() const
  {
    // typeid: use where the dynamic type of a polymorphic object must be known
    // and for static type identification. return object of type
    // "std::type_info"
    return typeid(*this).name();
  }

  // dispatcher that should be called by clients to intersect different shapes.
  //
  // users will invoke this function
  virtual void Intersect(const Shape*) const = 0;

  // specific intersection methods implemented by subclasses. if a subclass A
  // has a special way to intersect with subclass B then it should implement
  // IntersectWith(const B*)
  //
  // users should not have to invoke these functions, directly.
  virtual void IntersectWith(const Shape*) const {};
  virtual void IntersectWith(const Rectangle*) const {};
  virtual void IntersectWith(const Ellipse*) const {};
};

/*
  Rectangle : Shape
*/
class Rectangle : public Shape
{
 public:
  // rectangle's Intersect uses the input shape's IntersectWith method on itself
  //
  // users will invoke this function
  virtual void Intersect(const Shape* s) const
  {
    s->IntersectWith(this);
  }

  // IntersectWith definitions
  //
  // this is where the work is done
  virtual void IntersectWith(const Shape* s) const
  {
    std::cout << "Rectangle x Shape [names this=" << this->name()
              << ", s=" << s->name() << "]\n";
  }

  virtual void IntersectWith(const Rectangle* s) const
  {
    std::cout << "Rectangle x Rectangle [names this=" << this->name()
              << ", s=" << s->name() << "]\n";
  }
};

/*
  Ellipse : Shape
*/
class Ellipse : public Shape
{
 public:
  // Ellipse's Intersect uses the input shape's IntersectWith method on itself
  //
  // users will invoke this function
  virtual void Intersect(const Shape* s) const
  {
    s->IntersectWith(this);
  }

  // IntersectWith definitions
  //
  // this is where the work is done
  virtual void IntersectWith(const Shape* s) const
  {
    std::cout << "Ellipse x Shape [names this=" << this->name()
              << ", s=" << s->name() << "]\n";
  }

  virtual void IntersectWith(const Rectangle* s) const
  {
    std::cout << "Ellipse x Rectangle [names this=" << this->name()
              << ", s=" << s->name() << "]\n";
  }
};

#endif
