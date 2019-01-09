//
//  Student_new.hpp
//  StudentSystem
//
//  Created by Worlder on 2019/1/1.
//  Copyright © 2019 Worlder. All rights reserved.
//

#ifndef Student_new_hpp
#define Student_new_hpp

#include <stdio.h>
#include "Student_info.hpp"

class Student_new : public Student_info
{
private:
    double health;
    double looks;
    
public:
    double getHealth() { return health; }
    double getLooks() { return looks; }
    void assignHealth(double health) { this->health = health; }
    void assignLooks(double looks) { this->looks = looks; }
    
    void doSth(double, double, double, double, double);
    void love(ifstream& is, vector<Student_new>& vecStudNew);
    void breakUp(ifstream& is, vector<Student_new>& vecStudNew);
    
    static void init(vector<Student_new>& vecStudNew);
    static ifstream& readInstruct(ifstream& is,
                                  vector<Student_new>& vecStudNew, Dorm_info& dorm);
    static ifstream& readDoSth(ifstream& is, vector<Student_new>& vecStudNew,
                               const string& str, Dorm_info& dorm);
    static void readConfig(char* config, iptData& configData);
    static void readConfig(iptData& configData);
    static void putStudentInRoom(vector<Student_new>& vecStudNew, Dorm_info& dorm);
    static void saveData(vector<Student_new>& vecStudNew, Dorm_info& dorm);
    static void loadData(vector<Student_new>& vecStudNew, Dorm_info& dorm, iptData& configLoad);
    
};

#endif /* Student_new_hpp */
