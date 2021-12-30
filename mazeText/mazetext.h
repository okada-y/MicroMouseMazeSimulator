#ifndef MAZETEXT_H
#define MAZETEXT_H

#include <QString>
#include <vector>
#include "../maze.h"

using std::vector;

class MazeText
{
public:
    MazeText();
    template<class mazeSize_t>
    void vec2Text(const vector<vector<mazeSize_t>>&wallData);
    template<class mazeSize_t>
    vector<vector<mazeSize_t>> text2Vec();
    const QString* getText(){return &mazeText;}
    void inputText(const QString *filename);
    void outputText(const QString *filename);
    void clearText(void);

private:
    QString mazeText;
};

template<class mazeSize_t>
void MazeText::vec2Text(const vector<vector<mazeSize_t>>&wallData){

    size_t size;
    size = wallData.at(0).size();

    for(int i=0; i<NUM_OF_DIM; i++){
        for(int j=0; j<size; j++){
            mazeText.append(QString::number(wallData.at(i).at(j),32));
            mazeText.append(" ");
        }
        mazeText.append("\n");
    }
}
#endif // MAZETEXT_H
