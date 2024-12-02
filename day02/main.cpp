#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

int main()
{
   std::ifstream file( TEST );
   std::string   str;
   size_t        safe;
   while ( getline( file, str ) )
   {
      std::stringstream line{ str };

      std::vector<int32_t> vec;
      int32_t n;
      while( ! line.eof() )
      {
         line >> n;
         vec.push_back( n );
      }

      bool isIncreasing = ( vec[0]< vec[1] );
      if ( vec[0] == vec[1] )
      {
         continue;
      }

      bool skip = false;
      for ( size_t i = 0; i < vec.size() - 1; ++i )
      {
         size_t j = i + 1;
         if ( vec[ i ] == vec[ j ] )
         {
            skip = true;
            break;
         }

         if ( isIncreasing )
         {
            if( vec[i] > vec[j] || vec[j] != std::clamp( vec[j], vec[i]+1, vec[i]+3  ) )
            {
               skip = true;
               break;
            }
         }
         else
         {
            if( vec[i] < vec[j] || vec[j] != std::clamp( vec[j], vec[i]-3, vec[i]-1  ) )
            {
               skip = true;
               break;
            }
         }
      }

      if ( skip )
         continue;

      safe++;
   }

   std::cout << safe;
}
