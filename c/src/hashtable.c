inline unsigned int h_ab(int k,
                         unsigned int a, int b,
                         unsigned int p, unsigned int m)
{
  return ((a*k + b) % p) % m;
}
