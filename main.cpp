#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/* Splitting and searching algorithm
 *
 * @author Kirilin Anton
 * @version 1.0
 * @since 10.02.2021
 */
using namespace std;
// open files to write and read
ofstream outf("output.txt");
ifstream inf("input.txt");

/*
 * This function gets as a parameters string of text and reference to a vector of strings,
 * where it will store all sentences after splitting text by dots
 *
 */
void splitting(string str,vector<string>& sentences){
sentences.push_back(str);
    unsigned int splitAt;
    unsigned int splitLen = 1;
    string currentText;
    while (true)
    {
        currentText = sentences.back();
        splitAt = currentText.find('.');
        if(splitAt == string::npos) //if there is no dots in the remaining text
        {

            break;
        }
        sentences.back()=currentText.substr(0,splitAt)+'.';
        sentences.push_back(currentText.substr(splitAt+splitLen,currentText.size()-(splitAt+splitLen)));
    }
    //because if the text ended by dot, this algorithm will push back to the vector an empty string,that need to be deleted
    if (sentences.back().empty()){sentences.erase(sentences.end());}
    // To avoid unneeded space at the beginning of sentence remove it in cycle
    for (int i =0;i<sentences.size();i++){
        if (i!=0){sentences[i]=sentences[i].substr(1,sentences[i].size());}
    }

}

/*
 * This function allows to uppercase the specified word. As a parameters it gets vector of sentences
 * and the specified word.
 * It writes into the output.txt file number of sentences that contains this word, if it's more than 0
 * after number it write sentences itself with uppercased word.
 *
 */

void upperCasting(vector<string>& sentences,string& word){
unsigned int foundAtPos;
vector<string> editedSentences;
    string editedword =word;
    transform(editedword.begin(),editedword.end(),editedword.begin(), ::toupper);

for (int i=0;i<sentences.size();i++){
    bool changesHappened=false;
    string currentSentence=sentences[i];
    foundAtPos=currentSentence.find(word);
    while (foundAtPos!= string::npos){
        currentSentence.replace(foundAtPos,editedword.size(),editedword);
        changesHappened=true;
        foundAtPos=currentSentence.find(word);
        }
    if (changesHappened){
        editedSentences.push_back(currentSentence);
    }
}
outf <<editedSentences.size()<<endl; // number of sentences
for (int i =0; i<editedSentences.size();i++){
    outf <<editedSentences[i]<<endl; // write edited sentences(if they were)
}



}
int main() {
string str;

getline (inf,str); // get a line of the text

vector<string> sentences;
splitting(str,sentences); //call splitting function, out result in the sentences vector
int quantity;

inf >> quantity; //get a number of words
vector<string> words;
for (int i =0;i< quantity+1;i++){
    getline(inf,str);
    words.push_back(str);
}
// because it reads the line after the number of words we need to delete this useless string
words.erase(words.begin());

for (int i=0;i<words.size();i++) {
    upperCasting(sentences, words[i]);
}

}
