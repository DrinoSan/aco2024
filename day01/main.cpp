#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

#define TEST "test"
#define INPUT "input"

int main()
{
   std::ifstream file(TEST);
   std::string str;
   std::vector<int32_t> l;
   std::vector<int32_t> r;
   while (getline(file, str))
   {
      std::stringstream line{ str };

      int32_t ln;
      int32_t rn;
      line >> ln >> rn;
      l.push_back( ln );
      r.push_back( rn );
   }

   std::sort( l.begin(), l.end() );
   std::sort( r.begin(), r.end() );

   int32_t sum;
   for( size_t i = 0; i < l.size(); ++i )
   {
      std::cout << l[i] << " " << r[i] << "\n";
      sum += std::abs( l[i] - r[i] );
   }

   std::cout << sum;

}
