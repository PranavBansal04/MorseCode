#include <bits/stdc++.h>
#include <string>
using namespace std;
//needed for calculating size of the arrays
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

//function to convert given data to morse code or string
//takes 2 parameters and returns a string
//first parameter is the chracter that needs to be converted
//2nd parameter tells what should be done with the character
//whether it should be converted to string or morse code
//if check is true then it will be converted to morse code
//otherwise it will be converted to string
string morseEncode(string x,bool check) {
    //array of different characters
    string character[]={"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    //array of corresponding morse codes at the same indices
    string morse[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.","--.","....","..",
                       ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    //initializing the size of the array
    int size = my_sizeof(character)/my_sizeof(character[0]);
    //if check is true
    if(check){
            //find corresponding morse code for the character
        for (int i = 0; i<size; i++){
        if(x==character[i]){
            return morse[i];
        }
    }
    }
    //if check is false
    else{
            //find corresponding character for the morse code
        for (int i = 0; i<size; i++){
        if(x==morse[i]){
            return character[i];
        }
    }}


  return NULL;
}
//converts words to morse code and vice versa
void morseCode(string s,bool check) {
  for (int i = 0; s[i]; i++) {
        //converts char to string
      std:: string k(1,s[i]);
      cout << morseEncode(k,check);
  }
  cout << endl;
}
//converts chracter to morse code and vice versa
void translatechar(string s,bool check){
    cout << morseEncode(s,check);

}

//main driver function
int main() {
    //variable for input choice
  int choose;
  //display menu
  cout<<"Select an option: \n"<<endl;
  cout<<"1.Character to Morse Code\n2.Morse Code to Character\n3.String to Morse Code \n4.Morse Code to String"<<endl;
  //input for choice
  cin>>choose;
  //variable for ipnut data
  string data;
  cout<<"Enter data to be translated:"<<endl;
    //call the appropriate function for the selected options
  if(choose==1)
  {
      cin>>data;
      cout<<"Morse code:"<<endl;
      //pass true as the 2nd argument so that function may know
      //what we want to do with the given data
      translatechar(data,true);
  }
  if(choose==2){
        cin>>data;
      cout<<"String:"<<endl;
      //pass false as 2nd argument
      translatechar(data,false);
  }
  if(choose==3){
      cin>>data;
    cout<<"Morse code:"<<endl;
      morseCode(data,true);
  }
  //for this option we will first need to store every character in a vector
  //because if we directly start reading characters from input string then we
  //will not get the correct answer
  //thats why space separated input is taken for morse code
  if(choose==4){
      vector<string> words;
      //string for creating a separate character/group of characters from the input string
      string value="";
  cout<<"Please put space between characters."<<endl;
  //stops cin from taking input
  cin.ignore();
  //take whole line as input
  getline(cin,data,'\n');
  //iterate over the line and separate characters by space
  //and store in the array
  for(int i=0;i<data.size();i++)
  {
      //if the character is a space
      if(data[i]==' ')
      {
          //insert value variable to the vector
          words.push_back(value);
          //reinitialize value to null
          //so that next group of characters can be stored
          value="";
          continue;
      }
      //add the characters to the value
      value = value+data[i];
  }
  //for the last group of words there will be no space in the last
  //so this value will not actually be inserted inside the vector
  //but it will be stored in the value variable
  //so now after the execution of the loop, the last group of characters
  //can be inserted into the vector
  words.push_back(value);

  cout<<"String:"<<endl;
  //convert those morse codes into corresponding characters
  for(int i=0;i<words.size();i++)
  {
      translatechar(words[i],false);
  }

  }

  return 0;
}
