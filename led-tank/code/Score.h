#ifndef __SCORE_H__
#define __SCORE_H__

#include <string>
using namespace std;

class Score{
private:
    int NextScoreTable[4];
    int SensorID;
public:
    Score();
    ~Score();
    int* getNextScoreTable();
    int getSensorID();
    int ParsePayload();
};


#endif


