
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

enum class DIRECTION
{
   UP,
   RIGHT,
   DOWN,
   LEFT,
   WRAP_UP
};

// So I can use ++ on direction field and if it reaches WRAP_UP it then just
// begins from RIGHT again
DIRECTION& operator++( DIRECTION& dir )
{
   dir =  static_cast<DIRECTION>( ( static_cast<int32_t>( dir ) + 1 ) %
                                  static_cast<int32_t>( DIRECTION::WRAP_UP ) );
   return dir;
}

int main()
{
   std::ifstream            file( TEST );
   int64_t                  result{};
   std::string              str;
   std::vector<std::string> text;
   while ( getline( file, str ) )
   {
      text.push_back( str );
   }

   std::pair<int32_t, int32_t> traveler;
   std::vector<std::pair<int32_t, int32_t>> visited;   // x,y

   // Finding the possiton of our traveler
   for ( int32_t y = 0; y < text.size(); ++y )
   {
      for ( int32_t x = 0; x < text[ y ].size(); ++x )
      {
         if ( text[ y ][ x ] == '^' )
         {
            // We found it
            traveler.first  = x;
            traveler.second = y;
            visited.push_back( std::make_pair( x, y ) );
         }
      }
   }

   DIRECTION                                d{ DIRECTION::UP };
   bool done { false };
   while ( true )
   {
      int32_t x = traveler.first;
      int32_t y = traveler.second;
      switch ( d )
      {
      case DIRECTION::UP:
      {
         // We go alllll the way until we hit a #
         while ( y - 1 >= 0 && text[ y - 1 ][ x ] != '#' )
         {
            --y;
            visited.push_back( std::make_pair( x, y ) );
            std::cout << "Adding " << x << " " << y << '\n';
         }

         // We exited the maze
         if ( y - 1 < 0 )
         {
            done = true;
            break;
         }
      }
      break;

      case DIRECTION::RIGHT:
      {
         // We go alllll the way until we hit a #
         while ( x + 1 < text[ y ].size() && text[ y ][ x + 1 ] != '#' )
         {
            ++x;
            visited.push_back( std::make_pair( x, y ) );
         }

         // We exited the maze
         if ( x + 1 >= text[ y ].size() )
         {
            done = true;
            break;
         }
      }
      break;

      case DIRECTION::DOWN:
      {
         // We go alllll the way until we hit a #
         while ( y + 1 < text.size() && text[ y + 1 ][ x ] != '#' )
         {
            ++y;
            visited.push_back( std::make_pair( x, y ) );
         }

         // We exited the maze
         if ( y + 1 >= text.size() )
         {
            done = true;
            break;
         }
      }
      break;

      case DIRECTION::LEFT:
      {
         // We go alllll the way until we hit a #
         while ( x - 1 >= 0 && text[ y  ][ x - 1 ] != '#' )
         {
            --x;
            visited.push_back( std::make_pair( x, y ) );
         }

         // We exited the maze
         if ( x - 1 < 0 )
         {
            done = true;
            break;
         }

      }
      break;
      }

      ++d;
      traveler.first = x;
      traveler.second = y;

      if( done )
      {
         std::sort( visited.begin(), visited.end() );
         auto newEnd = std::unique( visited.begin(), visited.end() );
         visited.erase( newEnd, visited.end() );
         std::cout << "Result: " << visited.size() << '\n';
         return 69;
      }
   }
}
