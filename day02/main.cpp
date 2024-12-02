#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"

bool isPairValid( int32_t i, int32_t j, bool isInc ) {}

int main()
{
   std::ifstream file( INPUT );
   std::string   str;
   size_t        safe{};
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

      int isIncreasing = 0;
      if ( vec[ 0 ] < vec[ 1 ] )
      {
         isIncreasing = 1;
      }
      if ( vec[ 0 ] > vec[ 1 ] )
      {
         isIncreasing = -1;
      }
      if ( vec[0] == vec[1] )
      {
         isIncreasing = 0;
      }

      int32_t c = 0;

      int32_t steps{ 0 };
      int32_t tries{ 0 };
      size_t  i = 0;
      size_t  j = 1;

      bool skip{ false };
      bool tryRepair{ false };
      int32_t oldIsIncrease = isIncreasing;
      while ( true )
      {
         if ( tryRepair )
         {
            ++tries;
            if ( i == 0 )
            {
               // No way we can decrease I so i have to increase j
               ++j;
               ++i;
               steps     = 1;
               tryRepair = false;
               continue;
            }

            if ( j == vec.size() - 1 )
            {
               --i;
               steps        = -1;
               tryRepair    = false;
               isIncreasing = oldIsIncrease;
               continue;
            }

            // First we go left
            if ( steps == 0 )
            {
               --i;
               steps     = -1;
               tryRepair = false;
               continue;
            }

            if ( steps == -1 )
            {
               ++i;
               ++j;
               steps     = 1;
               tryRepair = false;
               continue;
            }

            if ( steps == 1 )
            {
               tries = 99999;
            }
         }

         if ( tries > 2 )
         {
            skip = true;
            break;
         }

         if ( i >= vec.size() || j >= vec.size() )
         {
            break;
         }

         oldIsIncrease = isIncreasing;
         if ( vec[ i ] < vec[ j ] )
         {
            isIncreasing = 1;
         }
         if ( vec[ i ] > vec[ j ] )
         {
            isIncreasing = -1;
         }
         if ( vec[ i ] == vec[ j ] )
         {
            isIncreasing = 0;
         }

         // Wer das liest, hdgdl gib nicht auf

         if ( oldIsIncrease != isIncreasing )
         {
            if( oldIsIncrease == 0 && i == 0 )
            {
               tryRepair = true;
               continue;
            }
            else if ( i != 0 )
            {
               tryRepair = true;
               continue;
            }
         }

         if ( isIncreasing == 0 )
         {
            tryRepair = true;
            continue;
         }

// Du kannst es schaffen
         if ( isIncreasing == -1 && vec[ i ] > vec[ j ] &&
              vec[ j ] != std::clamp( vec[ j ], vec[ i ] - 3, vec[ i ] - 1 ) )
         {
            tryRepair = true;
            continue;
         }

         // Denk an Thomas die Lokomotive
         else if ( isIncreasing == 1 && vec[ i ] < vec[ j ] &&
                   vec[ j ] !=
                       std::clamp( vec[ j ], vec[ i ] + 1, vec[ i ] + 3 ) )
         {
            tryRepair = true;
            continue;
         }

         ++i;
         ++j;
      }

      if ( !skip )
      {
         ++safe;
      }
   }

   std::cout << safe;
}
