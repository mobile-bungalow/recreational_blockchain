#include <cstdint>
#include <vector>
#include "blockchain.h"
#include "block.h"
using namespace std;


blockchain::blockchain()
{
    _vChain.push_back(block(0, "Somebody once told me"));
    _nDifficulty = 4;
}

void blockchain::AddBlock(block newBlock)
{
    newBlock.sPrevHash = _GetLastBlock().getHash();
    newBlock.MineBlock(_nDifficulty);
    _vChain.push_back(newBlock);
}


block blockchain::_GetLastBlock() const
{
return _vChain.back();
}

