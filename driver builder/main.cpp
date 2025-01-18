#include <iostream>
#include <fstream>
#include "data.h" // replace your rawdata here

bool CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
    std::ofstream file_ofstream(desired_file_path, std::ios_base::out | std::ios_base::binary);

    if (!file_ofstream.write(address, size))
    {
        file_ofstream.close();
        return false;
    }

    file_ofstream.close();
    return true;
}

int main()
{
    const char* datapath = "C:\\Users\\schepparon\\Desktop\\driver.sys"; // change the path and the file ending if you're not building a driver

    if (!CreateFileFromMemory(datapath, reinterpret_cast<const char*>(data), sizeof(data)))
    {
        std::cerr << "Failed to create file: " << datapath << std::endl;
        return 1;
    }

    std::cout << "File Created successfully: " << datapath << std::endl;
    return 0;
}
