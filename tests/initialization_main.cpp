class widget
{};


int main(void)
{
  widget w;                   // (a)

  widget w();                 // (b)
  widget w{};                 // (c)
  
  widget w(x);                // (d)
  widget w{x};                // (e)

  widget w = x;               // (f)
  widget w = {x};             // (g)

  auto w = x;                 // (h)
  auto w = widget{x};         // (i)
}
