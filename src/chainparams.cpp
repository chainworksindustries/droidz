// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xd4;
        pchMessageStart[1] = 0x13;
        pchMessageStart[2] = 0xe5;
        pchMessageStart[3] = 0xb2;
        vAlertPubKey = ParseHex("042d131e26e26900eb9fd053cd9f16a9a2894ad5ebbd551be1a4bd23bc016ed91528241bcff222989769417eb10cdb679228c9d55023679be17f0bd3a16e6fbeba");
        nDefaultPort = 5914;
        nRPCPort = 5915;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        
        const char* pszTimestamp = "http://www.bbc.co.uk/news/uk-35196493";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1451480642, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1451480642;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact(); 
        genesis.nNonce   = 152456;

        hashGenesisBlock = genesis.GetHash();
        
        // genesis.GetHash() == 00005e5044b1a81bef73dd7fc302fe157a3537ed5188401622f17e04efb16f20
        // genesis.hashMerkleRoot == b86d3a400a5040d9e355b9ffb12cc1188c84fb8ac0da24f10d8323c2b87bf93a
        // genesis.nTime = 1445966961 
        // genesis.nNonce = 156245 

        assert(hashGenesisBlock == uint256("2763a81e7d1c9829c82e06789c2c0ba204182f51f29d58e58681c59151694576"));
        assert(genesis.hashMerkleRoot == uint256("f0e597ad1f9473d01d0593e00333baba4efecf24f52e219203955f8a80825f97"));

        vSeeds.push_back(CDNSSeedData("drz-seed01.chainworksindustries.com", "drz-seed01.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed02.chainworksindustries.com", "drz-seed02.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed03.chainworksindustries.com", "drz-seed03.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed04.chainworksindustries.com", "drz-seed04.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed05.chainworksindustries.com", "drz-seed05.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed06.chainworksindustries.com", "drz-seed06.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed07.chainworksindustries.com", "drz-seed07.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed08.chainworksindustries.com", "drz-seed08.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed09.chainworksindustries.com", "drz-seed09.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed10.chainworksindustries.com", "drz-seed10.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed11.chainworksindustries.com", "drz-seed11.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed12.chainworksindustries.com", "drz-seed12.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed13.chainworksindustries.com", "drz-seed13.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed14.chainworksindustries.com", "drz-seed14.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed15.chainworksindustries.com", "drz-seed15.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed16.chainworksindustries.com", "drz-seed16.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed17.chainworksindustries.com", "drz-seed17.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed18.chainworksindustries.com", "drz-seed18.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed19.chainworksindustries.com", "drz-seed19.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed20.chainworksindustries.com", "drz-seed20.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed21.chainworksindustries.com", "drz-seed21.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed22.chainworksindustries.com", "drz-seed22.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed23.chainworksindustries.com", "drz-seed23.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed24.chainworksindustries.com", "drz-seed24.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed25.chainworksindustries.com", "drz-seed25.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed26.chainworksindustries.com", "drz-seed26.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed27.chainworksindustries.com", "drz-seed27.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed28.chainworksindustries.com", "drz-seed28.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed29.chainworksindustries.com", "drz-seed29.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed30.chainworksindustries.com", "drz-seed30.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed31.chainworksindustries.com", "drz-seed31.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed32.chainworksindustries.com", "drz-seed32.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed33.chainworksindustries.com", "drz-seed33.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed34.chainworksindustries.com", "drz-seed34.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed35.chainworksindustries.com", "drz-seed35.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed36.chainworksindustries.com", "drz-seed36.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed37.chainworksindustries.com", "drz-seed37.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed38.chainworksindustries.com", "drz-seed38.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed39.chainworksindustries.com", "drz-seed39.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed40.chainworksindustries.com", "drz-seed40.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed41.chainworksindustries.com", "drz-seed41.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed42.chainworksindustries.com", "drz-seed42.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed43.chainworksindustries.com", "drz-seed43.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed44.chainworksindustries.com", "drz-seed44.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed45.chainworksindustries.com", "drz-seed45.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed46.chainworksindustries.com", "drz-seed46.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed47.chainworksindustries.com", "drz-seed47.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed48.chainworksindustries.com", "drz-seed48.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed49.chainworksindustries.com", "drz-seed49.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed50.chainworksindustries.com", "drz-seed50.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed51.chainworksindustries.com", "drz-seed51.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed52.chainworksindustries.com", "drz-seed52.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed53.chainworksindustries.com", "drz-seed53.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed54.chainworksindustries.com", "drz-seed54.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed55.chainworksindustries.com", "drz-seed55.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed56.chainworksindustries.com", "drz-seed56.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed57.chainworksindustries.com", "drz-seed57.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed58.chainworksindustries.com", "drz-seed58.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed59.chainworksindustries.com", "drz-seed59.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed60.chainworksindustries.com", "drz-seed60.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed61.chainworksindustries.com", "drz-seed61.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed62.chainworksindustries.com", "drz-seed62.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed63.chainworksindustries.com", "drz-seed63.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed64.chainworksindustries.com", "drz-seed64.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed65.chainworksindustries.com", "drz-seed65.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed66.chainworksindustries.com", "drz-seed66.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed67.chainworksindustries.com", "drz-seed67.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed68.chainworksindustries.com", "drz-seed68.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed69.chainworksindustries.com", "drz-seed69.chainworksindustries.com"));
        vSeeds.push_back(CDNSSeedData("drz-seed70.chainworksindustries.com", "drz-seed70.chainworksindustries.com"));	    
        
        base58Prefixes[PUBKEY_ADDRESS] = {3};
        base58Prefixes[SCRIPT_ADDRESS] = {85};
        base58Prefixes[SECRET_KEY] = {153};
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

		nLastPOWBlock = 23825;
        nPOSStartBlock = 1;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x5a;
        pchMessageStart[1] = 0xd2;
        pchMessageStart[2] = 0x7c;
        pchMessageStart[3] = 0x8e;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        vAlertPubKey = ParseHex("042d13eb10cdb679228c9ae26e26900eb9fd053cd9f46a9a2c076ed97528247bcff222989769437894ad5ebbd551beda4bd23bd55023679be77f0bd3a16e6fbeba");
        nDefaultPort = 25914;
        nRPCPort = 25915;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();; 
        genesis.nNonce = 35117;

        //assert(hashGenesisBlock == uint256("0x9672529bc958a440a8acd061d914120d44c914a06454b82d3e1cd68fe4f1f916"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = {97};
        base58Prefixes[SCRIPT_ADDRESS] = {196};
        base58Prefixes[SECRET_KEY]     = {239};
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};


        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
		
		nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
