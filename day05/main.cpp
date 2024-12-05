#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

int main()
{
   std::ifstream                                   file( TEST );
   int64_t                                         result{};
   std::string                                     str;
   std::map<std::string, std::vector<std::string>> prec;
   while ( getline( file, str ) )
   {
      if ( str.empty() )
         break;

      std::string left;
      std::string right;

      size_t j = 0;
      for ( size_t i = 0; i < str.size(); ++i )
      {
         if ( str[ i ] == '|' )
         {
            j = ++i;
            break;
         }

         left += str[ i ];
      }

      for ( ; j < str.size(); ++j )
      {
         right += str[ j ];
      }

      prec[ left ].push_back( right );
   }

   while ( getline( file, str ) )
   {

      std::vector<std::string> numbers;
      size_t                   pos = 0;
      std::string              num;
      while ( ( pos = str.find( ',' ) ) != std::string::npos )
      {
         num = str.substr( 0, pos );
         numbers.push_back( num );
         str.erase( 0, pos + 1 );
      }

      numbers.push_back( str );

      bool allValid{ true };
      for ( size_t i = 0; i < numbers.size(); ++i )
      {
         // Check all numbers before current number and check if preconditions
         // hold
         auto precVec = prec[ numbers[ i ] ];
         for ( size_t j = 0; j <= i; ++j )
         {
            if ( std::find( precVec.begin(), precVec.end(), numbers[ j ] ) !=
                 precVec.end() )
            {
               allValid = false;
            }
         }
      }

      if ( allValid == true )
      {
         // Get middle number
         result += std::stoi( numbers[ numbers.size() / 2 ] );
      }
   }

   std::cout << "Result: " << result << '\n';
}
