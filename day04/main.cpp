#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

std::vector<std::string> text;

bool checkNESW( int32_t x, int32_t y )
{
   // CHECK NORTH EAST LIMIT
   if ( ( y - 1 ) < 0 )
   {
      // no space left
      return false;
   }

   if ( ( x + 1 ) >= text[ y ].size() )
   {
      return false;
   }

   // CHECK SOUTH WEST LIMIT
   if ( ( y + 1 ) >= text.size() )
   {
      // no space left
      return false;
   }

   if ( ( x - 1 ) < 0 )
   {
      return false;
   }

   /// UPPER RIGHT
   if ( text[ y - 1 ][ x + 1 ] == 'M' && text[ y + 1 ][ x - 1 ] == 'S' )
   {
      return true;
   }

   if ( text[ y - 1 ][ x + 1 ] == 'S' && text[ y + 1 ][ x - 1 ] == 'M' )
   {
      return true;
   }

   return false;
}

bool checkNWSE( int32_t x, int32_t y )
{
   // CHECK NW LIMITS
   if ( ( y - 1 ) < 0 )
   {
      // no space left
      return false;
   }

   if ( ( x - 1 ) < 0 )
   {
      return false;
   }

   // CHECK SE LIMITS
   if ( ( y + 1 ) >= text.size() )
   {
      // no space left
      return false;
   }

   if ( ( x + 1 ) >= text[ y ].size() )
   {
      return false;
   }

   if ( text[ y - 1 ][ x - 1 ] == 'M' && text[ y + 1 ][ x + 1 ] == 'S' )
   {
      return true;
   }

   if ( text[ y - 1 ][ x - 1 ] == 'S' && text[ y + 1 ][ x + 1 ] == 'M' )
   {
      return true;
   }

   return false;
}

int main()
{
   std::ifstream file( TEST );
   int64_t       result{};
   std::string   str;
   while ( getline( file, str ) )
   {
     text.push_back( str );
   }


  for( int32_t y = 0; y < text.size(); ++y )
  {
     for( int32_t x = 0; x < text[y].size(); ++x )
     {
        if ( text[ y ][ x ] != 'A' )
        {
           continue;
        }

        if ( checkNESW( x, y ) && checkNWSE( x, y ) )
        {
           ++result;
        }
     }
  }

  std::cout << "RESULT: " << result << '\n';

}
