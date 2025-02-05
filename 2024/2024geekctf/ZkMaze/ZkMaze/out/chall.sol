pragma solidity >=0.7.0 <0.9.0;

import {Groth16Verifier} from "./verifier.sol";

contract Challenge {
    Groth16Verifier public verifier;
    bool flag;

    constructor() {
        verifier = new Groth16Verifier();
        flag = false;
    }

    function verifyProof(
        uint[2] calldata _pA,
        uint[2][2] calldata _pB,
        uint[2] calldata _pC
    ) public returns (bool) {
        uint[26] memory _pubSignals = [uint(24), uint(0), uint(1), uint(0), uint(1), uint(1), uint(0), uint(1), uint(1), uint(0), uint(0), uint(0), uint(1), uint(1), uint(1), uint(0), uint(1), uint(0), uint(1), uint(1), uint(0), uint(1), uint(0), uint(1), uint(1), uint(0)];

        flag = verifier.verifyProof(_pA, _pB, _pC, _pubSignals);
        return flag;
    }

    function isSolved() public view returns (bool) {
        return flag;
    }
}