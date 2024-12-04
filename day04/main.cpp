#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

std::vector<std::string> text;

// ............ x
// .
// .
// .
// .
// .
// y
// PART 1
// bool checkN( int32_t x, int32_t y )
//{
//   // Because we only check north direction we dont care for chexks in x dir
//
//   // First check if we have even enough space to check upwards
//   if( ( y - 3 ) < 0 )
//   {
//      // no space left
//      return false;
//   }
//
//   if( text[y-1][x] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y-2][x] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y-3][x] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " N x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y-1][x] << text[y-2][x] << text[y-3][x] <<
//   '\n'; std::cout << "+++++++++++++++++++++++++++++++\n";
//
//   return true;
//}
//
// bool checkNE( int32_t x, int32_t y )
//{
//   if( ( y - 3 ) < 0 )
//   {
//      // no space left
//      return false;
//   }
//
//   if( ( x + 3 ) >= text[y].size() )
//   {
//      return false;
//   }
//
//   if( text[y-1][x+1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y-2][x+2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y-3][x+3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " NE x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y-1][x+1] << text[y-2][x+2] <<
//   text[y-3][x+3] << '\n'; std::cout << "+++++++++++++++++++++++++++++++\n";
//   return true;
//}
//
// bool checkE( int32_t x, int32_t y )
//{
//   if( ( x + 3 ) >= text[y].size() )
//   {
//      return false;
//   }
//
//   if( text[y][x+1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y][x+2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y][x+3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " E x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y][x+1] << text[y][x+2] << text[y][x+3] <<
//   '\n'; std::cout << "+++++++++++++++++++++++++++++++\n"; return true;
//}
//
// bool checkSE( int32_t x, int32_t y )
//{
//   if( ( y + 3 ) >= text.size() )
//   {
//      // no space left
//      return false;
//   }
//
//   if( ( x + 3 ) >= text[y].size() )
//   {
//      return false;
//   }
//
//   if( text[y+1][x+1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y+2][x+2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y+3][x+3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " SE x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y+1][x+1] << text[y+2][x+2] <<
//   text[y+3][x+3] << '\n'; std::cout << "+++++++++++++++++++++++++++++++\n";
//   return true;
//}
//
// bool checkS( int32_t x, int32_t y )
//{
//   if( ( y + 3 ) >= text.size() )
//   {
//      // no space left
//      return false;
//   }
//
//   if( text[y+1][x] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y+2][x] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y+3][x] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " S x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y+1][x] << text[y+2][x] << text[y+3][x] <<
//   '\n'; std::cout << "+++++++++++++++++++++++++++++++\n"; return true;
//}
//
// bool checkSW( int32_t x, int32_t y )
//{
//   if( ( y + 3 ) >= text.size() )
//   {
//      // no space left
//      return false;
//   }
//
//   if( ( x - 3 ) < 0 )
//   {
//      return false;
//   }
//
//   if( text[y+1][x-1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y+2][x-2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y+3][x-3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " SW x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y+1][x-1] << text[y+2][x-2] <<
//   text[y+3][x-3] << '\n'; std::cout << "+++++++++++++++++++++++++++++++\n";
//   return true;
//}
//
// bool checkW( int32_t x, int32_t y )
//{
//   if( ( x - 3 ) < 0 )
//   {
//      return false;
//   }
//
//   if( text[y][x-1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y][x-2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y][x-3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " W x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y][x-1] << text[y][x-2] << text[y][x-3] <<
//   '\n'; std::cout << "+++++++++++++++++++++++++++++++\n"; return true;
//}
//
//
// bool checkNW( int32_t x, int32_t y )
//{
//   if( ( y - 3 ) < 0 )
//   {
//      // no space left
//      return false;
//   }
//
//   if( ( x - 3 ) < 0 )
//   {
//      return false;
//   }
//
//   if( text[y-1][x-1] != 'M' )
//   {
//      return false;
//   }
//
//   if( text[y-2][x-2] != 'A' )
//   {
//      return false;
//   }
//
//   if( text[y-3][x-3] != 'S' )
//   {
//      return false;
//   }
//
//   std::cout << "-------------------------------\n";
//   std::cout << " NW x: " << x <<" y: " << y << '\n';
//   std::cout << text[y][x] << text[y-1][x-1] << text[y-2][x-2] <<
//   text[y-3][x-3] << '\n'; std::cout << "+++++++++++++++++++++++++++++++\n";
//   return true;
//}

//========

bool checkN( int32_t x, int32_t y )
{
   // Because we only check north direction we dont care for chexks in x dir

   // First check if we have even enough space to check upwards
   if ( ( y - 1 ) < 0 )
   {
      // no space left
      return false;
   }

   if( text[y-1][x] != 'M' )
   {
      return false;
   }

   if( text[y-2][x] != 'A' )
   {
      return false;
   }

   if( text[y-3][x] != 'S' )
   {
      return false;
   }

   std::cout << "-------------------------------\n";
   std::cout << " N x: " << x <<" y: " << y << '\n';
   std::cout << text[y][x] << text[y-1][x] << text[y-2][x] << text[y-3][x] << '\n';
   std::cout << "+++++++++++++++++++++++++++++++\n";

   return true;
}

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
        // PART 1
        // if( text[y][x] != 'X' )
        //{
        //   continue;
        //}

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
