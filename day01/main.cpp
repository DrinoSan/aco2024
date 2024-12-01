#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

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
      sum += std::abs( l[i] - r[i] );
   }

   std::cout << sum;

   // PART TWO
   std::map<int32_t, int32_t> counter;
   for ( const auto& n : l )
   {
      counter[ n ] = 0;
   }

   for ( const auto& n : r )
   {
      if ( counter.count( n ) == 0 )
      {
         continue;
      }

      counter[ n ]++;
   }

   sum = 0;
   for ( const auto& i : l )
   {
      sum += counter[ i ] * i;
   }

   std::cout << "\nPART 2\n" << sum;
}
