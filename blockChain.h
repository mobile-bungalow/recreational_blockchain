#include <cstdint>
#include <vector>
#include "block.h"
#pragma once
using namespace std;

class blockchain
{

public:
    blockchain();
 
    void AddBlock(block bNew);
 
private:
    uint32_t _nDifficulty;
    vector<block> _vChain;
 
    block _GetLastBlock() const;

};

