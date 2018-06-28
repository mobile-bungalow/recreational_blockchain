#include "block.h"
#include <string>
#include <sstream>


block::block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}

string block::getHash() 
{
	return _sHash;
}


