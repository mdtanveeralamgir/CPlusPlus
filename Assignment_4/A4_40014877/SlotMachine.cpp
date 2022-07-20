#include "SlotMachine.h"

SlotMachine::SlotMachine(size_t tok)
:token{tok}
{}

void SlotMachine::run() {
  this->displayInstruction(); //Displaying instruction
  int tokenEntered {this->getToken()}; //Getting the token amount

  while (this->token && tokenEntered){ //If token and inserted token are getter than zero
  this->makeShapes(); //Making shapes
  //findTwoSimilarShapes() returns true if 2 shape's name is similar and shapesEqualScrSize() returns true if 2 shape's screen size is similar
  if(this->findTwoSimilarShapes() && this->shapesEqualScrSize()){
    this->jackpot(tokenEntered); //Calculates the jackpot win prize based on the token user inserted
  }
  else if(this->threeSimilarShapes()){ //Returns true if 3 shape's name is similar
    this->twoTimesBet(tokenEntered); //Inserted token gets doubled and added with the existing token
  }
  else if (this->midScrIsGreater()){ //Returns true if screen area of the middle shape is bigger than left and right combine
    this->oneTimeBet(tokenEntered); //The entered token gets added
  }
  else if(this->sameLeftRight()){ //Returns true if Left and Right shape's name is same
    this->winsNothing(); // Display message for this bet and token does not get modified
  }
  else {
    this->loseBet(tokenEntered); //Otherwise user lose bet and token gets deducted from existing token
  }
  if(this->token) //User gets to enter the token amount if the token is not zero
    tokenEntered = this->getToken();
  }

  if(this->token){ //User has token left and choose not to play anymore
    cout << "Thank you for playing, come back soon!\n"
            "Be sure you cash in your remaining " << this->token << " tokens at the bar!" << endl;
  }
  cout << "Game Over." << endl;
}

//Making the shapes
void SlotMachine::makeShapes() {
  srand (time(NULL)); // initialize random seed.
  for(size_t i {0}; i < 3; i++){ //Filling up reel with 3 random shapes
    this->makeShape(i); //Making shapes and assign it to
  }
  //Draw 3 shapes and returns in the form of 2D vector
  Grid box_0 = reel[0]->draw(); //Shape 1
  Grid box_1 = reel[1]->draw(); //Shape 2
  Grid box_2 = reel[2]->draw(); //Shape 3
  this->displayBoxes(box_0, box_1, box_2); //Display 3 shapes side by side
}

//Make shapes randomly
void SlotMachine::makeShape(int i) {
  int ranInt {rand() % 4}; //Generating random int from 0 - 3
  int ranWidth {rand() % 25 + 1}; //Generating random width from 1 - 25

  switch (ranInt) {
    case 0:
      reel[i].reset(new Rhombus(ranWidth)); //Creating Rhombus if random int is zero
      break;
    case 1:
      reel[i].reset(new AcuteTriangle(ranWidth)); //Creating Acute Triangle if random int is 1
      break;
    case 2:
      reel[i].reset(new RightTriangle(ranWidth)); //Creating Right Triangle if random int is 2
      break;
    default:
      int ranHeight {rand() % 25 + 1}; //Generating random height for Rectangle from 1 to 25
      reel[i].reset(new Rectangle(ranWidth, ranHeight)); //Creating Rectangle otherwise
  }

}

//Displaying shapes side by side
void SlotMachine::displayBoxes(const Grid &box_0, const Grid &box_1, const Grid &box_2) const {
  //Getting the max height
  size_t maxHeight = std::max(reel[0]->getBoxHeight(), reel[1]->getBoxHeight());
  maxHeight = std::max(maxHeight, reel[2]->getBoxHeight());

  this->printingBorder(); //Printing the top border

  for (size_t height{0}; height < maxHeight; height++) { //Looping though using max height amount 3 shapes
    cout << "| "; //very left border with a padding

    for(int i {0}; i < reel[0]->getBoxWidth(); i++){ //Looping through using width of first box
      if(height < reel[0]->getBoxHeight())
        cout << box_0[height][i]; //Printing the rows of the first shapes
      else
        cout << " "; // When there is no more row left then Print blank space
      }

    cout << " | "; //2nd border from left with both side padding

    for(int i {0}; i < reel[1]->getBoxWidth(); i++){ //Looping through using width of 2nd box
      if(height < reel[1]->getBoxHeight())
        cout << box_1[height][i]; //Printing the rows of the 2nd shapes
      else
        cout << " "; //When there is no more row left then insert blank space
    }

    cout << " | "; //3nd border from left with both side padding

    for(int i {0}; i < reel[2]->getBoxWidth(); i++){ //Looping through using width of 3rd box
      if(height < reel[2]->getBoxHeight())
        cout << box_2[height][i]; //Printing the rows of the 3dd shapes
      else
        cout << " "; //When there is no more row left then insert blank space
    }

    cout << " |"; //Very last border with right side padding

    cout << endl;
  }

  this->printingBorder(); //Printing bottom border
  //Short description (Name, Height, Width) of 3 shapes
  cout << "(" << reel[0]->getShapeName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") ";
  cout << "(" << reel[1]->getShapeName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") ";
  cout << "(" << reel[2]->getShapeName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ") ";
  cout << endl;

}

/*
 * Getting the token amount from user
 */
int SlotMachine::getToken() const {
    int value{}; //To hold the value
    std::string garbage {}; //Clearing up the buffer
    cout << "\nHow much would you like to bet (enter 0 to quit)? "; //Message
    cin >> value; //Reading value from user
    while(!cin || value > this->token){ //To check if cin is bad or entered amount is higher than existing token
      cin.clear(); //Clean up cin
      std::getline(cin, garbage); //Clean up buffer
      if(value > this->token) //Display message if entered token is higher than existing token
        cout << "You can’t bet more than " <<  this->token << ", try again!" << endl;
      cin >> value; //Prompt again for the input
    std::getline(cin, garbage); //Finally clear the buffer again
    }
    return value;
}

/*
 * Calculate jackpot
 */

void SlotMachine::jackpot(int token) {
  this->token += token * 3; //3 times of the bet
  cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas\n" //Message
          "Congratulations! you win 3 times your bet: " << token * 3 <<'\n'
          << "You now have " << this->token << " tokens" << endl;
}

/*
 * Calculate 2 times bet
 */

void SlotMachine::twoTimesBet(int token) {
  this->token += token * 2; //2 times of the bet
  cout << "Three similar shapes\n" //Message
          "Congratulations! you win 2 times your bet: " << token * 2 <<'\n'
       << "You now have " << this->token << " tokens" << endl;
}

/*
 * Calculate 1 times bet
 */

void SlotMachine::oneTimeBet(int token) {
  this->token += token; //Added the bet
  cout << "Middle > Left + Right, in Screen Areas\n" //Message
          "Congratulations! you win your bet: " << token <<'\n'
       << "You now have " << this->token << " tokens" << endl;
}

/*
 * When wins / lose nothing
 */
void SlotMachine::winsNothing() {
  cout << "Lucky this time!\n" //Message
          "You don’t win, you don’t lose, your are safe!\n"
       << "You now have " << this->token << " tokens" << endl;
}

/*
 * When lose the current bet
 */

void SlotMachine::loseBet(int token) {
  this->token -= token; //Deduct the bet

  if(this->token){ //If any token left
    cout << "Oh No!\n" //Message
            "You lose your bet\n"
         << "You now have " << this->token << " tokens" << endl;
  }
  else{ //If token becomes zero
    cout << "Oh No!\n" //Message
            "You lose your bet\n"
         << "You just ran out of tokens. Better luck next time!" << endl;
  }
}

/*
 * Printing top and bottom border
 */

void SlotMachine::printingBorder() const {
  //Width of 3 shapes plus 6 padding + 2 border in between
  size_t totalWidth {reel[0]->getBoxWidth() + reel[1]->getBoxWidth() + reel[2]->getBoxWidth() + 8};
  cout << "+"; //First + printing
  for(size_t i {0}; i < totalWidth; i++){
    if(i == reel[0]->getBoxWidth() + 2) // + after first shape
      cout << "+";
    else if (i == reel[0]->getBoxWidth() + reel[1]->getBoxWidth() + 5) // + after 2nd shape
      cout << "+";
    else
      cout << "-";
  }
  cout << "+" << endl; //Last + printing
}

/*
 * For jackpot
 * Finding 2 similar shapes
 */
bool SlotMachine::findTwoSimilarShapes() const {
  //If shape 0 is same as 1 or 2
  if((reel[0]->getShapeName() == reel[1]->getShapeName()) || (reel[0]->getShapeName() == reel[2]->getShapeName())){
    return true;
  } else if(reel[1]->getShapeName() == reel[2]->getShapeName()){ //If shape 1 and 2 are similar
    return true;
  } else{
    return false;
  }
}

/*
 * for Jackpot
 * Finding shapes with equal screen size
 */

bool SlotMachine::shapesEqualScrSize() const {
  //If shape 0 is same as 1 or 2
  if((reel[0]->screenArea() == reel[1]->screenArea()) || (reel[0]->screenArea() == reel[2]->screenArea())){
    return true;
  } else if(reel[1]->screenArea() == reel[2]->screenArea()){ //If shape 1 and 2 are similar
    return true;
  } else{
    return false;
  }
}

/*
 * For 2x
 * finding 3 similar shapes
 */

bool SlotMachine::threeSimilarShapes() const {
  //Comparing shape 1 vs 2 and then 2 vs 3
  return (reel[0]->getShapeName() == reel[1]->getShapeName()) && (reel[1]->getShapeName() == reel[2]->getShapeName());
}

/*
 * For 1x
 * Mix scr is greater than Left + Right
 */

bool SlotMachine::midScrIsGreater() const {
  //Middle shape's screen area compare with left + right
  return reel[1]->screenArea() > (reel[0]->screenArea() + reel[2]->screenArea());
}

/*
 * For no changes in the token
 * When left and right shape is same
 */

bool SlotMachine::sameLeftRight() const {
  //Comparing left and right shapes name
  return reel[0]->getShapeName() == reel[2]->getShapeName();
}


/*
 * The very first message to show the instruction
 */
void SlotMachine::displayInstruction() const {
  cout << "Welcome to 3-Reel Lucky Slot Machine Game!\n"
  << "Each reel will randomly display one of four shapes, each in 25 sizes.\n"
  << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas\n"
  << "To win 2 x bet, get 3 similar shapes\n"
  << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas\n"
  << "To win or lose nothing, get same Left and Right shapes\n"
  << "Otherwise, you lose your bet.\n"
  << "You start with 10 free slot tokens!" << endl; //Message
}


