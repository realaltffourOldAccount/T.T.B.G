#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class csv_saver {
   public:
    csv_saver();
    ~csv_saver();

    // sets the data that is then converted to the csv format
    void SetRaw(std::vector<std::vector<std::string> >);
    // converts and saves the csv format of the setraw function
    void Save(std::string);

   private:
    std::vector<std::vector<std::string> > m_Raw;
};
