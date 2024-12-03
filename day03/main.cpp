#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define TEST  "test"
#define INPUT "input"


bool hasNext( size_t curIdx, size_t size )
{
   return ( ( curIdx + 1 ) < size );
}

char peek( std::string& str, size_t curIdx )
{
   return str[ curIdx + 1 ];
}

int main()
{
   std::ifstream file( TEST );
   std::string   str;
   int64_t       result{};
      bool isEnabled{ true };
   while ( getline( file, str ) )
   {
      size_t size{ str.size() };

      std::cout << str << std::endl;
      for ( size_t i = 0; i < str.size() - 2; ++i )
      {
         if ( str[ i ] == 'm' && str[ i + 1 ] == 'u' && str[ i + 2 ] == 'l' )
         {
            i += 2;
            if ( !hasNext( i, size ) )
            {
               // We have no next char so we reached end of line and can say
               // goodbye
               // std::cout << "UUUU\n";
               continue;
            }

            if ( peek( str, i ) != '(' )
            {
               continue;
            }

            // To consume the '('
            ++i;

            // Here we know the next one is a '(' so we can consume the it
            // (going to the next index We can initialize j with i + 1 because
            // hasNext returned true
            std::string ln;
            int32_t     lnInteger;
            bool        shouldBreak{ false };
            size_t      tmp{ 0 };
            for ( size_t j = i + 1; j < str.size(); ++j )
            {
               // Here we now want to consme the numbers inside braces 123,123
               // seem slike they are integers
               //  so we consume char by char until we hit:
               //  - a , means we consumed the first number anything else is a
               //  invalid mul

               if ( !isdigit( str[ j ] ) )
               {
                  // Okay so the char is not a number this means it must be a
                  // ',' and if it is a ',' then we must already have consued a
                  // number otherwise it is invalid
                  if ( !ln.empty() && str[ j ] == ',' )
                  {
                     // We have something like mul(123,
                     tmp       = j;
                     lnInteger = std::stoi( ln );
                     // std::cout << "LEFT INTEGER: " << lnInteger << '\n';
                     break;
                  }

                  if ( ln.empty() )
                  {
                     // We know that number is empty and the current char is not
                     // a number basically something like mul(e
                     shouldBreak = true;
                     break;
                  }

                  if ( str[ j ] != ',' )
                  {
                     shouldBreak = true;
                     break;
                  }
               }

               ln += str[ j ];
            }

            if ( shouldBreak )
            {
               continue;
            }

            // If we arrive here we consumed mul(123,
            // Now we need to consume all numbers until ')'
            std::string rn;
            int32_t     rInteger;
            shouldBreak = { false };
            bool allGood{ false };
            for ( size_t j = tmp + 1; j < str.size(); ++j )
            {
               // Here we now want to consme the numbers inside braces 123,123
               // seem slike they are integers
               //  so we consume char by char until we hit:
               //  - a , means we consumed the first number anything else is a
               //  invalid mul

               if ( !isdigit( str[ j ] ) )
               {
                  //  Okay so the char is not a number this means it must be a
                  //  ',' and if it is a ',' then we must already have consued a
                  //  number otherwise it is invalid
                  if ( !ln.empty() && str[ j ] == ')' )
                  {
                     // We have something like mul(123,
                     rInteger = std::stoi( rn );
                     allGood = true;   // we finished
                     tmp     = j;
                     break;
                  }

                  if ( ln.empty() )
                  {
                     // We know that number is empty and the current char is not
                     // a number basically something like mul(e
                     shouldBreak = true;
                     break;
                  }

                  if ( str[ j ] != ')' )
                  {
                     shouldBreak = true;
                     break;
                  }
               }

               rn += str[ j ];
            }

            if ( shouldBreak )
            {
               continue;
            }

            if ( allGood )
            {
               // We can multiply
               if( isEnabled == false )
               {
                  continue;
               }

               result += lnInteger * rInteger;
               continue;
            }
         }
         else if ( str[ i ] == 'd' && str[ i + 1 ] == 'o' )
         {
            if ( i + 3 < str.size() && str[ i + 2 ] == '(' &&
                 str[ i + 3 ] == ')' )
            {
               // It's a do()
               isEnabled = true;
               continue;
            }

            if ( i + 6 < str.size() && str[ i + 2 ] == 'n' &&
                 str[ i + 3 ] == '\'' && str[ i + 4 ] == 't' &&
                 str[ i + 5 ] == '(' && str[ i + 6 ] == ')' )
            {
               // It's don't() can't touch this
               isEnabled = false;
               continue;
            }
         }
      }
   }
   std::cout << "RESULT: " << result << '\n';
}
