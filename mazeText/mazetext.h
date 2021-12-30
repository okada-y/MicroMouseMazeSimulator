#ifndef MAZETEXT_H
#define MAZETEXT_H

#include <QString>
#include <QStringList>
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
    void setText(const QString *text){mazeText = *text;}
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
            mazeText.append(QString::number(wallData.at(i).at(j),16));
            mazeText.append(" ");
        }
        mazeText.append("\n");
    }
}

template<class mazeSize_t>
vector<vector<mazeSize_t>> MazeText::text2Vec(){

    QStringList list = mazeText.split(' ');
    size_t size = (list.size()-1)/2;
    vector<vector<mazeSize_t>> vec(2,vector<mazeSize_t>(size));
    for(int i=0; i<NUM_OF_DIM; i++){
        for(int j=0; j<size; j++){
            vec.at(i).at(j) = list.at( j + i * (size + 1)).toULong();
        }
    }
    return vec;
}

#endif // MAZETEXT_H
