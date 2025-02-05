// SPDX-License-Identifier: GPL-3.0
/*
    Copyright 2021 0KIMS association.

    This file is generated with [snarkJS](https://github.com/iden3/snarkjs).

    snarkJS is a free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    snarkJS is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with snarkJS. If not, see <https://www.gnu.org/licenses/>.
*/

pragma solidity >=0.7.0 <0.9.0;

contract Groth16Verifier {
    // Scalar field size
    uint256 constant r    = 21888242871839275222246405745257275088548364400416034343698204186575808495617;
    // Base field size
    uint256 constant q   = 21888242871839275222246405745257275088696311157297823662689037894645226208583;

    // Verification Key data
    uint256 constant alphax  = 7051581398795658047098616416746991463259497567284720352841771791544643754490;
    uint256 constant alphay  = 12384673583815251987633672415222277713759582219621512331825949127831231382984;
    uint256 constant betax1  = 21675643824140873064710121183416626280944074702206974997915204330193500602463;
    uint256 constant betax2  = 3479911281389497188276181464873616768789864875409635388577110338213143370378;
    uint256 constant betay1  = 19221634599632170527935673979653860635418951616530277495994323810814291966304;
    uint256 constant betay2  = 10086631739466102156229843716236738887995344000212261689904601261190876049852;
    uint256 constant gammax1 = 11559732032986387107991004021392285783925812861821192530917403151452391805634;
    uint256 constant gammax2 = 10857046999023057135944570762232829481370756359578518086990519993285655852781;
    uint256 constant gammay1 = 4082367875863433681332203403145435568316851327593401208105741076214120093531;
    uint256 constant gammay2 = 8495653923123431417604973247489272438418190587263600148770280649306958101930;
    uint256 constant deltax1 = 5431551270852182242312259173362750213734388809315189051158733581984624361069;
    uint256 constant deltax2 = 12339150053653283057962007325807356142464812417301735625281752180650287466374;
    uint256 constant deltay1 = 20202337615757679149925211582748218656781381733926506757671282315464609599062;
    uint256 constant deltay2 = 13584883410990918127403530991712948685668720749417631452445699388899711055657;

    
    uint256 constant IC0x = 5019450746114716096856453732810066794961598421213860032527055441890090479646;
    uint256 constant IC0y = 12861165214675417574452005072044798546531829576508865865745081981585663733391;
    
    uint256 constant IC1x = 17079862152209327933076595303795810333339908161476973063558531357759798550596;
    uint256 constant IC1y = 21023992654093451315806861525456460880887158687998830519784019657178497722823;
    
    uint256 constant IC2x = 17756697508338689329788746124545090469005736547160561410891634428481864085202;
    uint256 constant IC2y = 6930288839886818567816627871376528575798362493577890595406442172039419175792;
    
    uint256 constant IC3x = 18177060099159503336361510361580544430495067524132544289389300182513014213431;
    uint256 constant IC3y = 18168514405486407301810150400128604310438906554253016412569925343367736352796;
    
    uint256 constant IC4x = 7030496354149221167326276577316743019599123622011855902075510704547435139584;
    uint256 constant IC4y = 13331565609893738190249963505430006963656532794157904876457983386383472386666;
    
    uint256 constant IC5x = 5357941788724019852546606345572870268116528857505097524743306514898179664085;
    uint256 constant IC5y = 11327325577699666632876184802710443837041033000726584446261693669857175109383;
    
    uint256 constant IC6x = 14548469547899395643729708128536183817773170578189479520890054363412955476130;
    uint256 constant IC6y = 16092546116451533628975193255538025765821118973775120842273040219311607094291;
    
    uint256 constant IC7x = 4154652438977497959904758519399093684387078236205019855535156710399021396994;
    uint256 constant IC7y = 8769613809124052910425810532230067790607979769059307490014213984275791328578;
    
    uint256 constant IC8x = 5509168285914317921191154125008849377174726321516149540225908969968019741222;
    uint256 constant IC8y = 1241045825421521212295984219581685390924335160067829755725135041008648422573;
    
    uint256 constant IC9x = 21402592928326005488391802551636724478134333120991488192838766406079733328360;
    uint256 constant IC9y = 8502495182636790999786890126819356580923760502462773445170733069292834658762;
    
    uint256 constant IC10x = 1731709408266321271619817352516555042319929689852627402468271365935456077115;
    uint256 constant IC10y = 17177228988352313790700386205701885780681483554487874558418952916127047930121;
    
    uint256 constant IC11x = 6535510403591411586320184398897206384087220983398873862318517990820711020748;
    uint256 constant IC11y = 19410709353024031867726790622509965877746621316352024387233142102167141126232;
    
    uint256 constant IC12x = 19744398178989504025577353645538322675243895998815282353186807683663211431702;
    uint256 constant IC12y = 901293277394306793202025237217568409782956118466097702681435277617490606097;
    
    uint256 constant IC13x = 8789979855816036320219336703996506757075944030712812950763808135441645423204;
    uint256 constant IC13y = 18761755811275062549831165372051492942549521162957814341289303466748142512090;
    
    uint256 constant IC14x = 12194483243068257703126162954696241199331867672783521217052146390792000967937;
    uint256 constant IC14y = 14369135559272181128188431162193235165100912728349635726369815999075937928247;
    
    uint256 constant IC15x = 19634320834855634175030697604966561233846366406031021134556748487428276220844;
    uint256 constant IC15y = 1177410617748112534653690177199166202134811182453836669111644971296138811180;
    
    uint256 constant IC16x = 8079468867994556333359895013219306387713267908866729371301929986073669861855;
    uint256 constant IC16y = 9984157679292712080077192292610383345343494083469723498984536566261010063775;
    
    uint256 constant IC17x = 17703040771200377886368138517583973611881047019130511126269185977543880036748;
    uint256 constant IC17y = 1928719370540652610649234162010284382941757083902568586385012406258315090622;
    
    uint256 constant IC18x = 21419313152196495190621263456769094208043552600277797912347265201792763097090;
    uint256 constant IC18y = 16377325087325147509082162741159120584818296991263965170030877946512117750774;
    
    uint256 constant IC19x = 14422042104928688357771631088811867553399808674826250314535133808454518440783;
    uint256 constant IC19y = 8764433765483600597575705552537885528412756789599037871817620911662924905990;
    
    uint256 constant IC20x = 3890531590751551098311928598856914013691883363400173937295211250036302215621;
    uint256 constant IC20y = 5137280561468541803285979348450776123782237051242717960879635826926738503885;
    
    uint256 constant IC21x = 20585128935958951695305426742798602862874105628645820644942045474320487403000;
    uint256 constant IC21y = 1746378988632637936259490152760580788231462233710239794473650328737651648795;
    
    uint256 constant IC22x = 21601517508355964366626636870035107357991998706616230142909938362790710934279;
    uint256 constant IC22y = 5195319743869015713670255415860722494132625390084653735662554323284514215052;
    
    uint256 constant IC23x = 18207255926144169947759199206378978438751802820513056760668747520581543720940;
    uint256 constant IC23y = 4464780610246253571520216950104922557806455440083141990529950933801040188245;
    
    uint256 constant IC24x = 6116420505777043990841622293809833744050887237076784502188345086629249147803;
    uint256 constant IC24y = 11593192965214526286424105790216147204973596480047295881422455654897380442574;
    
    uint256 constant IC25x = 20401293102823865142799251219272891536635637393607720992416042420180860079311;
    uint256 constant IC25y = 9346520043633860777037184993679209415994053839522645784616813019916747769206;
    
    uint256 constant IC26x = 4076998742879297892865678102679859386514609625171490161539576377201022247973;
    uint256 constant IC26y = 16441665597686406778202585425013021131563850050390530734677613099086625591761;
    
 
    // Memory data
    uint16 constant pVk = 0;
    uint16 constant pPairing = 128;

    uint16 constant pLastMem = 896;

    function verifyProof(uint[2] calldata _pA, uint[2][2] calldata _pB, uint[2] calldata _pC, uint[26] calldata _pubSignals) public view returns (bool) {
        assembly {
            function checkField(v) {
                if iszero(lt(v, q)) {
                    mstore(0, 0)
                    return(0, 0x20)
                }
            }
            
            // G1 function to multiply a G1 value(x,y) to value in an address
            function g1_mulAccC(pR, x, y, s) {
                let success
                let mIn := mload(0x40)
                mstore(mIn, x)
                mstore(add(mIn, 32), y)
                mstore(add(mIn, 64), s)

                success := staticcall(sub(gas(), 2000), 7, mIn, 96, mIn, 64)

                if iszero(success) {
                    mstore(0, 0)
                    return(0, 0x20)
                }

                mstore(add(mIn, 64), mload(pR))
                mstore(add(mIn, 96), mload(add(pR, 32)))

                success := staticcall(sub(gas(), 2000), 6, mIn, 128, pR, 64)

                if iszero(success) {
                    mstore(0, 0)
                    return(0, 0x20)
                }
            }

            function checkPairing(pA, pB, pC, pubSignals, pMem) -> isOk {
                let _pPairing := add(pMem, pPairing)
                let _pVk := add(pMem, pVk)

                mstore(_pVk, IC0x)
                mstore(add(_pVk, 32), IC0y)

                // Compute the linear combination vk_x
                
                g1_mulAccC(_pVk, IC1x, IC1y, calldataload(add(pubSignals, 0)))
                
                g1_mulAccC(_pVk, IC2x, IC2y, calldataload(add(pubSignals, 32)))
                
                g1_mulAccC(_pVk, IC3x, IC3y, calldataload(add(pubSignals, 64)))
                
                g1_mulAccC(_pVk, IC4x, IC4y, calldataload(add(pubSignals, 96)))
                
                g1_mulAccC(_pVk, IC5x, IC5y, calldataload(add(pubSignals, 128)))
                
                g1_mulAccC(_pVk, IC6x, IC6y, calldataload(add(pubSignals, 160)))
                
                g1_mulAccC(_pVk, IC7x, IC7y, calldataload(add(pubSignals, 192)))
                
                g1_mulAccC(_pVk, IC8x, IC8y, calldataload(add(pubSignals, 224)))
                
                g1_mulAccC(_pVk, IC9x, IC9y, calldataload(add(pubSignals, 256)))
                
                g1_mulAccC(_pVk, IC10x, IC10y, calldataload(add(pubSignals, 288)))
                
                g1_mulAccC(_pVk, IC11x, IC11y, calldataload(add(pubSignals, 320)))
                
                g1_mulAccC(_pVk, IC12x, IC12y, calldataload(add(pubSignals, 352)))
                
                g1_mulAccC(_pVk, IC13x, IC13y, calldataload(add(pubSignals, 384)))
                
                g1_mulAccC(_pVk, IC14x, IC14y, calldataload(add(pubSignals, 416)))
                
                g1_mulAccC(_pVk, IC15x, IC15y, calldataload(add(pubSignals, 448)))
                
                g1_mulAccC(_pVk, IC16x, IC16y, calldataload(add(pubSignals, 480)))
                
                g1_mulAccC(_pVk, IC17x, IC17y, calldataload(add(pubSignals, 512)))
                
                g1_mulAccC(_pVk, IC18x, IC18y, calldataload(add(pubSignals, 544)))
                
                g1_mulAccC(_pVk, IC19x, IC19y, calldataload(add(pubSignals, 576)))
                
                g1_mulAccC(_pVk, IC20x, IC20y, calldataload(add(pubSignals, 608)))
                
                g1_mulAccC(_pVk, IC21x, IC21y, calldataload(add(pubSignals, 640)))
                
                g1_mulAccC(_pVk, IC22x, IC22y, calldataload(add(pubSignals, 672)))
                
                g1_mulAccC(_pVk, IC23x, IC23y, calldataload(add(pubSignals, 704)))
                
                g1_mulAccC(_pVk, IC24x, IC24y, calldataload(add(pubSignals, 736)))
                
                g1_mulAccC(_pVk, IC25x, IC25y, calldataload(add(pubSignals, 768)))
                
                g1_mulAccC(_pVk, IC26x, IC26y, calldataload(add(pubSignals, 800)))
                

                // -A
                mstore(_pPairing, calldataload(pA))
                mstore(add(_pPairing, 32), mod(sub(q, calldataload(add(pA, 32))), q))

                // B
                mstore(add(_pPairing, 64), calldataload(pB))
                mstore(add(_pPairing, 96), calldataload(add(pB, 32)))
                mstore(add(_pPairing, 128), calldataload(add(pB, 64)))
                mstore(add(_pPairing, 160), calldataload(add(pB, 96)))

                // alpha1
                mstore(add(_pPairing, 192), alphax)
                mstore(add(_pPairing, 224), alphay)

                // beta2
                mstore(add(_pPairing, 256), betax1)
                mstore(add(_pPairing, 288), betax2)
                mstore(add(_pPairing, 320), betay1)
                mstore(add(_pPairing, 352), betay2)

                // vk_x
                mstore(add(_pPairing, 384), mload(add(pMem, pVk)))
                mstore(add(_pPairing, 416), mload(add(pMem, add(pVk, 32))))


                // gamma2
                mstore(add(_pPairing, 448), gammax1)
                mstore(add(_pPairing, 480), gammax2)
                mstore(add(_pPairing, 512), gammay1)
                mstore(add(_pPairing, 544), gammay2)

                // C
                mstore(add(_pPairing, 576), calldataload(pC))
                mstore(add(_pPairing, 608), calldataload(add(pC, 32)))

                // delta2
                mstore(add(_pPairing, 640), deltax1)
                mstore(add(_pPairing, 672), deltax2)
                mstore(add(_pPairing, 704), deltay1)
                mstore(add(_pPairing, 736), deltay2)


                let success := staticcall(sub(gas(), 2000), 8, _pPairing, 768, _pPairing, 0x20)

                isOk := and(success, mload(_pPairing))
            }

            let pMem := mload(0x40)
            mstore(0x40, add(pMem, pLastMem))

            // Validate that all evaluations ∈ F
            
            checkField(calldataload(add(_pubSignals, 0)))
            
            checkField(calldataload(add(_pubSignals, 32)))
            
            checkField(calldataload(add(_pubSignals, 64)))
            
            checkField(calldataload(add(_pubSignals, 96)))
            
            checkField(calldataload(add(_pubSignals, 128)))
            
            checkField(calldataload(add(_pubSignals, 160)))
            
            checkField(calldataload(add(_pubSignals, 192)))
            
            checkField(calldataload(add(_pubSignals, 224)))
            
            checkField(calldataload(add(_pubSignals, 256)))
            
            checkField(calldataload(add(_pubSignals, 288)))
            
            checkField(calldataload(add(_pubSignals, 320)))
            
            checkField(calldataload(add(_pubSignals, 352)))
            
            checkField(calldataload(add(_pubSignals, 384)))
            
            checkField(calldataload(add(_pubSignals, 416)))
            
            checkField(calldataload(add(_pubSignals, 448)))
            
            checkField(calldataload(add(_pubSignals, 480)))
            
            checkField(calldataload(add(_pubSignals, 512)))
            
            checkField(calldataload(add(_pubSignals, 544)))
            
            checkField(calldataload(add(_pubSignals, 576)))
            
            checkField(calldataload(add(_pubSignals, 608)))
            
            checkField(calldataload(add(_pubSignals, 640)))
            
            checkField(calldataload(add(_pubSignals, 672)))
            
            checkField(calldataload(add(_pubSignals, 704)))
            
            checkField(calldataload(add(_pubSignals, 736)))
            
            checkField(calldataload(add(_pubSignals, 768)))
            
            checkField(calldataload(add(_pubSignals, 800)))
            
            checkField(calldataload(add(_pubSignals, 832)))
            

            // Validate all evaluations
            let isValid := checkPairing(_pA, _pB, _pC, _pubSignals, pMem)

            mstore(0, isValid)
             return(0, 0x20)
         }
     }
 }
