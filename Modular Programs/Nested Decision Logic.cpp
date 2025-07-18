/* Prompt: Create a program that determines if a player qualifies for a tournament based on score and rank.
   
   Description: Nested decision logic. If-else statements. User input. Relational operators. Prints text to console.
*/

#include <iostream>

using namespace std;

void is_qualified(int playerScore, int playerRank);

int main()
{ 
   int player_score_1;
   int player_rank_1;
    
   cout << "Enter player score: " << endl;
   cin >> player_score_1;
   cout << "Enter player rank: " << endl;
   cin >> player_rank_1;

   is_qualified(player_score_1, player_rank_1);

   return 0;
}   
 
void is_qualified(int playerScore, int playerRank) {
   if(playerScore >= 95) {
      if(playerRank <= 20) {
         cout << "Qualified" << endl;
      } else {
         cout << "Not Qualified" << endl;
      }
   } else {
      if(playerScore >= 85) {
         if(playerRank <= 40) {
            cout << "Qualified" << endl;
         } else {
            cout << "Not Qualified" << endl;
         }
      } else {
         if(playerScore >= 75) {
            if(playerRank <= 60) {
               cout << "Qualified" << endl;
            } else {
               cout << "Not Qualified" << endl;
            }
         } else {
            cout << "Not Qualified" << endl;
         }
      }
   }
}



