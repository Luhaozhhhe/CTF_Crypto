#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Num2Bits_0_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void Num2Bits_0_run(uint ctx_index, Circom_CalcWit *ctx);
void LessThan_1_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void LessThan_1_run(uint ctx_index, Circom_CalcWit *ctx);
void GreaterEqThan_2_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void GreaterEqThan_2_run(uint ctx_index, Circom_CalcWit *ctx);
void getMove_3_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void getMove_3_run(uint ctx_index, Circom_CalcWit *ctx);
void getMove_4_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void getMove_4_run(uint ctx_index, Circom_CalcWit *ctx);
void checkInMaze_5_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void checkInMaze_5_run(uint ctx_index, Circom_CalcWit *ctx);
void IsZero_6_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void IsZero_6_run(uint ctx_index, Circom_CalcWit *ctx);
void IsEqual_7_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void IsEqual_7_run(uint ctx_index, Circom_CalcWit *ctx);
void IsEqualN_8_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void IsEqualN_8_run(uint ctx_index, Circom_CalcWit *ctx);
void CheckNotBarrier_9_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void CheckNotBarrier_9_run(uint ctx_index, Circom_CalcWit *ctx);
void solve_10_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather);
void solve_10_run(uint ctx_index, Circom_CalcWit *ctx);
Circom_TemplateFunction _functionTable[11] = {
    Num2Bits_0_run,
    LessThan_1_run,
    GreaterEqThan_2_run,
    getMove_3_run,
    getMove_4_run,
    checkInMaze_5_run,
    IsZero_6_run,
    IsEqual_7_run,
    IsEqualN_8_run,
    CheckNotBarrier_9_run,
    solve_10_run};
Circom_TemplateFunction _functionTableParallel[11] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL};
uint get_main_input_signal_start() { return 1; }

uint get_main_input_signal_no() { return 41; }

uint get_total_signal_no() { return 19949; }

uint get_number_of_components() { return 976; }

uint get_size_of_input_hashmap() { return 256; }

uint get_size_of_witness() { return 16361; }

uint get_size_of_constants() { return 12; }

uint get_size_of_io_map() { return 0; }

void release_memory_component(Circom_CalcWit *ctx, uint pos)
{
    {

        if (pos != 0)
        {
            {

                if (ctx->componentMemory[pos].subcomponents)
                    delete[] ctx->componentMemory[pos].subcomponents;

                if (ctx->componentMemory[pos].subcomponentsParallel)
                    delete[] ctx->componentMemory[pos].subcomponentsParallel;

                if (ctx->componentMemory[pos].outputIsSet)
                    delete[] ctx->componentMemory[pos].outputIsSet;

                if (ctx->componentMemory[pos].mutexes)
                    delete[] ctx->componentMemory[pos].mutexes;

                if (ctx->componentMemory[pos].cvs)
                    delete[] ctx->componentMemory[pos].cvs;

                if (ctx->componentMemory[pos].sbct)
                    delete[] ctx->componentMemory[pos].sbct;
            }
        }
    }
}

// function declarations
// template declarations
void Num2Bits_0_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 0;
    ctx->componentMemory[coffset].templateName = "Num2Bits";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 1;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_0_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[6];
    FrElement lvar[4];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[0]);
    }
    {
        PFrElement aux_dest = &lvar[1];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        PFrElement aux_dest = &lvar[2];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[2]);
    }
    {
        PFrElement aux_dest = &lvar[3];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    Fr_lt(&expaux[0], &lvar[3], &circuitConstants[0]); // line circom 31
    while (Fr_isTrue(&expaux[0]))
    {
        {
            PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
            // load src
            Fr_shr(&expaux[1], &signalValues[mySignalStart + 253], &lvar[3]); // line circom 32
            Fr_band(&expaux[0], &expaux[1], &circuitConstants[2]);            // line circom 32
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_sub(&expaux[3], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)], &circuitConstants[2]); // line circom 33
        Fr_mul(&expaux[1], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)], &expaux[3]);           // line circom 33
        Fr_eq(&expaux[0], &expaux[1], &circuitConstants[1]);                                                     // line circom 33
        if (!Fr_isTrue(&expaux[0]))
            std::cout << "Failed assert in template/function " << myTemplateName << " line 33. "
                      << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
        assert(Fr_isTrue(&expaux[0]));
        {
            PFrElement aux_dest = &lvar[1];
            // load src
            Fr_mul(&expaux[2], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)], &lvar[2]); // line circom 34
            Fr_add(&expaux[0], &lvar[1], &expaux[2]);                                                    // line circom 34
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        {
            PFrElement aux_dest = &lvar[2];
            // load src
            Fr_add(&expaux[0], &lvar[2], &lvar[2]); // line circom 35
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        {
            PFrElement aux_dest = &lvar[3];
            // load src
            Fr_add(&expaux[0], &lvar[3], &circuitConstants[2]); // line circom 31
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_lt(&expaux[0], &lvar[3], &circuitConstants[0]); // line circom 31
    }
    Fr_eq(&expaux[0], &lvar[1], &signalValues[mySignalStart + 253]); // line circom 38
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 38. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    for (uint i = 0; i < 0; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void LessThan_1_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 1;
    ctx->componentMemory[coffset].templateName = "LessThan";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 2;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_1_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[4];
    FrElement lvar[1];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[3]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 3;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "n2b";
            Num2Bits_0_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 254;
            aux_cmp_num += 1;
        }
    }
    if (!Fr_isTrue(&circuitConstants[2]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 90. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&circuitConstants[2]));
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 253];
            // load src
            Fr_add(&expaux[1], &signalValues[mySignalStart + 1], &circuitConstants[4]); // line circom 96
            Fr_sub(&expaux[0], &expaux[1], &signalValues[mySignalStart + 2]);           // line circom 96
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        Num2Bits_0_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        Fr_sub(&expaux[0], &circuitConstants[2], &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 252]); // line circom 98
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    for (uint i = 0; i < 1; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void GreaterEqThan_2_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 2;
    ctx->componentMemory[coffset].templateName = "GreaterEqThan";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 2;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void GreaterEqThan_2_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[3];
    FrElement lvar[1];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[3]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 3;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "lt";
            LessThan_1_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 257;
            aux_cmp_num += 2;
        }
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            // end load src
            Fr_copy(aux_dest, &signalValues[mySignalStart + 2]);
        }
        // no need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
            // load src
            Fr_add(&expaux[0], &signalValues[mySignalStart + 1], &circuitConstants[2]); // line circom 138
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        LessThan_1_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        // end load src
        Fr_copy(aux_dest, &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
    }
    for (uint i = 0; i < 1; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void getMove_3_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 3;
    ctx->componentMemory[coffset].templateName = "getMove";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 1;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void getMove_3_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[6];
    FrElement lvar[1];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 4;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "GreaterThanStart";
            GreaterEqThan_2_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 260;
            aux_cmp_num += 3;
        }
    }
    {
        uint aux_create = 1;
        int aux_cmp_num = 3 + ctx_index + 1;
        uint csoffset = mySignalStart + 264;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "LessThanEnd";
            LessThan_1_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 257;
            aux_cmp_num += 2;
        }
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            // end load src
            Fr_copy(aux_dest, &signalValues[mySignalStart + 1]);
        }
        // no need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[1]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        GreaterEqThan_2_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        uint cmp_index_ref = 1;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            // end load src
            Fr_copy(aux_dest, &signalValues[mySignalStart + 1]);
        }
        // no need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
    }
    {
        uint cmp_index_ref = 1;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[5]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        LessThan_1_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 2];
        // load src
        Fr_sub(&expaux[3], &signalValues[mySignalStart + 1], &circuitConstants[1]); // line circom 53
        Fr_mul(&expaux[1], &circuitConstants[5], &expaux[3]);                       // line circom 53
        Fr_sub(&expaux[0], &expaux[1], &circuitConstants[2]);                       // line circom 53
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 3];
        // load src
        Fr_mul(&expaux[0], &signalValues[mySignalStart + 2], &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]); // line circom 55
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        Fr_mul(&expaux[0], &signalValues[mySignalStart + 3], &ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 56
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    for (uint i = 0; i < 2; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void getMove_4_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 4;
    ctx->componentMemory[coffset].templateName = "getMove";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 1;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void getMove_4_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[6];
    FrElement lvar[1];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[5]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 4;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "GreaterThanStart";
            GreaterEqThan_2_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 260;
            aux_cmp_num += 3;
        }
    }
    {
        uint aux_create = 1;
        int aux_cmp_num = 3 + ctx_index + 1;
        uint csoffset = mySignalStart + 264;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "LessThanEnd";
            LessThan_1_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 257;
            aux_cmp_num += 2;
        }
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            // end load src
            Fr_copy(aux_dest, &signalValues[mySignalStart + 1]);
        }
        // no need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[5]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        GreaterEqThan_2_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        uint cmp_index_ref = 1;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            // end load src
            Fr_copy(aux_dest, &signalValues[mySignalStart + 1]);
        }
        // no need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
    }
    {
        uint cmp_index_ref = 1;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[6]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        LessThan_1_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 2];
        // load src
        Fr_sub(&expaux[3], &signalValues[mySignalStart + 1], &circuitConstants[5]); // line circom 53
        Fr_mul(&expaux[1], &circuitConstants[5], &expaux[3]);                       // line circom 53
        Fr_sub(&expaux[0], &expaux[1], &circuitConstants[2]);                       // line circom 53
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 3];
        // load src
        Fr_mul(&expaux[0], &signalValues[mySignalStart + 2], &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]); // line circom 55
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        Fr_mul(&expaux[0], &signalValues[mySignalStart + 3], &ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 56
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    for (uint i = 0; i < 2; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void checkInMaze_5_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 5;
    ctx->componentMemory[coffset].templateName = "checkInMaze";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 2;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void checkInMaze_5_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[6];
    FrElement lvar[1];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[7]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 3];
        // load src
        Fr_geq(&expaux[1], &signalValues[mySignalStart + 1], &circuitConstants[1]); // line circom 65
        Fr_lt(&expaux[2], &signalValues[mySignalStart + 1], &circuitConstants[7]);  // line circom 65
        Fr_land(&expaux[0], &expaux[1], &expaux[2]);                                // line circom 65
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    Fr_sub(&expaux[3], &signalValues[mySignalStart + 3], &circuitConstants[2]); // line circom 66
    Fr_mul(&expaux[1], &signalValues[mySignalStart + 3], &expaux[3]);           // line circom 66
    Fr_eq(&expaux[0], &expaux[1], &circuitConstants[1]);                        // line circom 66
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 66. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 4];
        // load src
        Fr_geq(&expaux[1], &signalValues[mySignalStart + 2], &circuitConstants[1]); // line circom 67
        Fr_lt(&expaux[2], &signalValues[mySignalStart + 2], &circuitConstants[7]);  // line circom 67
        Fr_land(&expaux[0], &expaux[1], &expaux[2]);                                // line circom 67
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    Fr_sub(&expaux[3], &signalValues[mySignalStart + 4], &circuitConstants[2]); // line circom 68
    Fr_mul(&expaux[1], &signalValues[mySignalStart + 4], &expaux[3]);           // line circom 68
    Fr_eq(&expaux[0], &expaux[1], &circuitConstants[1]);                        // line circom 68
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 68. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        Fr_mul(&expaux[0], &signalValues[mySignalStart + 3], &signalValues[mySignalStart + 4]); // line circom 69
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    for (uint i = 0; i < 0; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void IsZero_6_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 6;
    ctx->componentMemory[coffset].templateName = "IsZero";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 1;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void IsZero_6_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[4];
    FrElement lvar[0];
    uint sub_component_aux;
    uint index_multiple_eq;
    Fr_neq(&expaux[0], &signalValues[mySignalStart + 1], &circuitConstants[1]); // line circom 30
    if (Fr_isTrue(&expaux[0]))
    {
        {
            PFrElement aux_dest = &signalValues[mySignalStart + 2];
            // load src
            Fr_div(&expaux[0], &circuitConstants[2], &signalValues[mySignalStart + 1]); // line circom 30
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
    }
    else
    {
        {
            PFrElement aux_dest = &signalValues[mySignalStart + 2];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[1]);
        }
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        Fr_neg(&expaux[2], &signalValues[mySignalStart + 1]);             // line circom 32
        Fr_mul(&expaux[1], &expaux[2], &signalValues[mySignalStart + 2]); // line circom 32
        Fr_add(&expaux[0], &expaux[1], &circuitConstants[2]);             // line circom 32
        // end load src
        Fr_copy(aux_dest, &expaux[0]);
    }
    Fr_mul(&expaux[1], &signalValues[mySignalStart + 1], &signalValues[mySignalStart + 0]); // line circom 33
    Fr_eq(&expaux[0], &expaux[1], &circuitConstants[1]);                                    // line circom 33
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 33. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    for (uint i = 0; i < 0; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void IsEqual_7_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 7;
    ctx->componentMemory[coffset].templateName = "IsEqual";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 2;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void IsEqual_7_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[3];
    FrElement lvar[0];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 3;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "isz";
            IsZero_6_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 3;
            aux_cmp_num += 1;
        }
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
            // load src
            Fr_sub(&expaux[0], &signalValues[mySignalStart + 2], &signalValues[mySignalStart + 1]); // line circom 43
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        IsZero_6_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 0];
        // load src
        // end load src
        Fr_copy(aux_dest, &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
    }
    for (uint i = 0; i < 1; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void IsEqualN_8_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 8;
    ctx->componentMemory[coffset].templateName = "IsEqualN";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 26;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[25]{0};
}

void IsEqualN_8_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[3];
    FrElement lvar[2];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[8]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 51;
        uint aux_dimensions[1] = {25};
        for (uint i = 0; i < 25; i++)
        {
            std::string new_cmp_name = "iseq" + ctx->generate_position_array(aux_dimensions, 1, i);
            IsEqual_7_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 6;
            aux_cmp_num += 2;
        }
    }
    {
        PFrElement aux_dest = &lvar[1];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    Fr_lt(&expaux[0], &lvar[1], &circuitConstants[8]); // line circom 10
    while (Fr_isTrue(&expaux[0]))
    {
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 25)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                IsEqual_7_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + 50]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                IsEqual_7_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
            // load src
            // end load src
            Fr_copy(aux_dest, &ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[1])) + 0)]].signalStart + 0]);
        }
        {
            PFrElement aux_dest = &lvar[1];
            // load src
            Fr_add(&expaux[0], &lvar[1], &circuitConstants[2]); // line circom 10
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_lt(&expaux[0], &lvar[1], &circuitConstants[8]); // line circom 10
    }
    for (uint i = 0; i < 25; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void CheckNotBarrier_9_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 9;
    ctx->componentMemory[coffset].templateName = "CheckNotBarrier";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 27;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void CheckNotBarrier_9_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[5];
    FrElement lvar[4];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[7]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 77;
        for (uint i = 0; i < 1; i++)
        {
            std::string new_cmp_name = "iseq";
            IsEqualN_8_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 201;
            aux_cmp_num += 51;
        }
    }
    {
        PFrElement aux_dest = &lvar[1];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        PFrElement aux_dest = &lvar[2];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    Fr_lt(&expaux[0], &lvar[2], &circuitConstants[7]); // line circom 27
    while (Fr_isTrue(&expaux[0]))
    {
        {
            PFrElement aux_dest = &lvar[3];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[1]);
        }
        Fr_lt(&expaux[0], &lvar[3], &circuitConstants[7]); // line circom 28
        while (Fr_isTrue(&expaux[0]))
        {
            {
                uint cmp_index_ref = 0;
                {
                    PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * ((Fr_toInt(&lvar[2]) * 5) + Fr_toInt(&lvar[3]))) + 25)];
                    // load src
                    Fr_mul(&expaux[1], &lvar[2], &circuitConstants[7]); // line circom 29
                    Fr_add(&expaux[0], &expaux[1], &lvar[3]);           // line circom 29
                    // end load src
                    Fr_copy(aux_dest, &expaux[0]);
                }
                // no need to run sub component
                ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
                assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
            }
            {
                PFrElement aux_dest = &lvar[3];
                // load src
                Fr_add(&expaux[0], &lvar[3], &circuitConstants[2]); // line circom 28
                // end load src
                Fr_copy(aux_dest, &expaux[0]);
            }
            Fr_lt(&expaux[0], &lvar[3], &circuitConstants[7]); // line circom 28
        }
        {
            PFrElement aux_dest = &lvar[2];
            // load src
            Fr_add(&expaux[0], &lvar[2], &circuitConstants[2]); // line circom 27
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_lt(&expaux[0], &lvar[2], &circuitConstants[7]); // line circom 27
    }
    {
        uint cmp_index_ref = 0;
        {
            PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 50];
            // load src
            Fr_mul(&expaux[1], &signalValues[mySignalStart + 26], &circuitConstants[7]); // line circom 32
            Fr_add(&expaux[0], &expaux[1], &signalValues[mySignalStart + 25]);           // line circom 32
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        // need to run sub component
        ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
        assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
        IsEqualN_8_run(mySubcomponents[cmp_index_ref], ctx);
    }
    {
        PFrElement aux_dest = &lvar[2];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    Fr_lt(&expaux[0], &lvar[2], &circuitConstants[7]); // line circom 33
    while (Fr_isTrue(&expaux[0]))
    {
        {
            PFrElement aux_dest = &lvar[3];
            // load src
            // end load src
            Fr_copy(aux_dest, &circuitConstants[1]);
        }
        Fr_lt(&expaux[0], &lvar[3], &circuitConstants[7]); // line circom 34
        while (Fr_isTrue(&expaux[0]))
        {
            {
                PFrElement aux_dest = &signalValues[mySignalStart + (((5 * Fr_toInt(&lvar[2])) + (1 * Fr_toInt(&lvar[3]))) + 27)];
                // load src
                Fr_mul(&expaux[0], &ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ((1 * ((Fr_toInt(&lvar[2]) * 5) + Fr_toInt(&lvar[3]))) + 0)], &signalValues[mySignalStart + (((5 * Fr_toInt(&lvar[2])) + (1 * Fr_toInt(&lvar[3]))) + 0)]); // line circom 35
                // end load src
                Fr_copy(aux_dest, &expaux[0]);
            }
            {
                PFrElement aux_dest = &lvar[1];
                // load src
                Fr_add(&expaux[0], &lvar[1], &signalValues[mySignalStart + (((5 * Fr_toInt(&lvar[2])) + (1 * Fr_toInt(&lvar[3]))) + 27)]); // line circom 36
                // end load src
                Fr_copy(aux_dest, &expaux[0]);
            }
            {
                PFrElement aux_dest = &lvar[3];
                // load src
                Fr_add(&expaux[0], &lvar[3], &circuitConstants[2]); // line circom 34
                // end load src
                Fr_copy(aux_dest, &expaux[0]);
            }
            Fr_lt(&expaux[0], &lvar[3], &circuitConstants[7]); // line circom 34
        }
        {
            PFrElement aux_dest = &lvar[2];
            // load src
            Fr_add(&expaux[0], &lvar[2], &circuitConstants[2]); // line circom 33
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_lt(&expaux[0], &lvar[2], &circuitConstants[7]); // line circom 33
    }
    Fr_eq(&expaux[0], &lvar[1], &circuitConstants[1]); // line circom 39
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 39. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    for (uint i = 0; i < 1; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void solve_10_create(uint soffset, uint coffset, Circom_CalcWit *ctx, std::string componentName, uint componentFather)
{
    ctx->componentMemory[coffset].templateId = 10;
    ctx->componentMemory[coffset].templateName = "solve";
    ctx->componentMemory[coffset].signalStart = soffset;
    ctx->componentMemory[coffset].inputCounter = 41;
    ctx->componentMemory[coffset].componentName = componentName;
    ctx->componentMemory[coffset].idFather = componentFather;
    ctx->componentMemory[coffset].subcomponents = new uint[60]{0};
}

void solve_10_run(uint ctx_index, Circom_CalcWit *ctx)
{
    FrElement *signalValues = ctx->signalValues;
    u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
    std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
    std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
    u64 myFather = ctx->componentMemory[ctx_index].idFather;
    u64 myId = ctx_index;
    u32 *mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
    bool *mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
    FrElement *circuitConstants = ctx->circuitConstants;
    std::string *listOfTemplateMessages = ctx->listOfTemplateMessages;
    FrElement expaux[8];
    FrElement lvar[8];
    uint sub_component_aux;
    uint index_multiple_eq;
    {
        PFrElement aux_dest = &lvar[0];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[7]);
    }
    {
        PFrElement aux_dest = &lvar[1];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[9]);
    }
    {
        uint aux_create = 0;
        int aux_cmp_num = 795 + ctx_index + 1;
        uint csoffset = mySignalStart + 4318;
        uint aux_dimensions[1] = {15};
        for (uint i = 0; i < 15; i++)
        {
            std::string new_cmp_name = "move_x" + ctx->generate_position_array(aux_dimensions, 1, i);
            getMove_3_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 521;
            aux_cmp_num += 6;
        }
    }
    {
        uint aux_create = 15;
        int aux_cmp_num = 885 + ctx_index + 1;
        uint csoffset = mySignalStart + 12133;
        uint aux_dimensions[1] = {15};
        for (uint i = 0; i < 15; i++)
        {
            std::string new_cmp_name = "move_y" + ctx->generate_position_array(aux_dimensions, 1, i);
            getMove_4_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 521;
            aux_cmp_num += 6;
        }
    }
    {
        uint aux_create = 30;
        int aux_cmp_num = 0 + ctx_index + 1;
        uint csoffset = mySignalStart + 73;
        uint aux_dimensions[1] = {15};
        for (uint i = 0; i < 15; i++)
        {
            std::string new_cmp_name = "check" + ctx->generate_position_array(aux_dimensions, 1, i);
            checkInMaze_5_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 5;
            aux_cmp_num += 1;
        }
    }
    {
        uint aux_create = 45;
        int aux_cmp_num = 15 + ctx_index + 1;
        uint csoffset = mySignalStart + 148;
        uint aux_dimensions[1] = {15};
        for (uint i = 0; i < 15; i++)
        {
            std::string new_cmp_name = "checkMaze" + ctx->generate_position_array(aux_dimensions, 1, i);
            CheckNotBarrier_9_create(csoffset, aux_cmp_num, ctx, new_cmp_name, myId);
            mySubcomponents[aux_create + i] = aux_cmp_num;
            csoffset += 278;
            aux_cmp_num += 52;
        }
    }
    {
        PFrElement aux_dest = &lvar[2];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[10]);
    }
    {
        PFrElement aux_dest = &lvar[3];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        PFrElement aux_dest = &lvar[4];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[2]);
    }
    {
        PFrElement aux_dest = &lvar[5];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[5]);
    }
    {
        PFrElement aux_dest = &lvar[6];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[11]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 41];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        PFrElement aux_dest = &signalValues[mySignalStart + 57];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    {
        PFrElement aux_dest = &lvar[7];
        // load src
        // end load src
        Fr_copy(aux_dest, &circuitConstants[1]);
    }
    Fr_lt(&expaux[0], &lvar[7], &circuitConstants[9]); // line circom 89
    while (Fr_isTrue(&expaux[0]))
    {
        Fr_eq(&expaux[4], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)], &circuitConstants[10]); // line circom 90
        Fr_eq(&expaux[5], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)], &circuitConstants[1]);  // line circom 90
        Fr_lor(&expaux[3], &expaux[4], &expaux[5]);                                                               // line circom 90
        Fr_eq(&expaux[4], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)], &circuitConstants[2]);  // line circom 90
        Fr_lor(&expaux[2], &expaux[3], &expaux[4]);                                                               // line circom 90
        Fr_eq(&expaux[3], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)], &circuitConstants[11]); // line circom 90
        Fr_lor(&expaux[1], &expaux[2], &expaux[3]);                                                               // line circom 90
        Fr_eq(&expaux[2], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)], &circuitConstants[5]);  // line circom 90
        Fr_lor(&expaux[0], &expaux[1], &expaux[2]);                                                               // line circom 90
        if (!Fr_isTrue(&expaux[0]))
            std::cout << "Failed assert in template/function " << myTemplateName << " line 90. "
                      << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
        assert(Fr_isTrue(&expaux[0]));
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 0);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                getMove_3_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 15);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 26)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                getMove_4_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            PFrElement aux_dest = &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 41)];
            // load src
            Fr_add(&expaux[0], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 41)], &ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[7])) + 0)]].signalStart + 0]); // line circom 95
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        {
            PFrElement aux_dest = &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 57)];
            // load src
            Fr_add(&expaux[0], &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[7])) + 57)], &ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[7])) + 15)]].signalStart + 0]); // line circom 96
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 30);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 41)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                checkInMaze_5_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 30);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 57)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                checkInMaze_5_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        Fr_eq(&expaux[0], &ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[7])) + 30)]].signalStart + 0], &circuitConstants[2]); // line circom 100
        if (!Fr_isTrue(&expaux[0]))
            std::cout << "Failed assert in template/function " << myTemplateName << " line 100. "
                      << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
        assert(Fr_isTrue(&expaux[0]));
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 45);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 0];
                // load src
                // end load src
                Fr_copyn(aux_dest, &signalValues[mySignalStart + 1], 25);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 25))
            {
                CheckNotBarrier_9_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 45);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 25];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 41)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                CheckNotBarrier_9_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            uint cmp_index_ref = ((1 * Fr_toInt(&lvar[7])) + 45);
            {
                PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 26];
                // load src
                // end load src
                Fr_copy(aux_dest, &signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[7]) + 1)) + 57)]);
            }
            // run sub component if needed
            if (!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1))
            {
                CheckNotBarrier_9_run(mySubcomponents[cmp_index_ref], ctx);
            }
        }
        {
            PFrElement aux_dest = &lvar[7];
            // load src
            Fr_add(&expaux[0], &lvar[7], &circuitConstants[2]); // line circom 89
            // end load src
            Fr_copy(aux_dest, &expaux[0]);
        }
        Fr_lt(&expaux[0], &lvar[7], &circuitConstants[9]); // line circom 89
    }
    Fr_mul(&expaux[4], &signalValues[mySignalStart + 72], &circuitConstants[7]); // line circom 106
    Fr_add(&expaux[2], &signalValues[mySignalStart + 56], &expaux[4]);           // line circom 106
    Fr_eq(&expaux[0], &signalValues[mySignalStart + 0], &expaux[2]);             // line circom 106
    if (!Fr_isTrue(&expaux[0]))
        std::cout << "Failed assert in template/function " << myTemplateName << " line 106. "
                  << "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
    assert(Fr_isTrue(&expaux[0]));
    for (uint i = 0; i < 60; i++)
    {
        uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
        if (index_subc != 0)
            release_memory_component(ctx, index_subc);
    }
}

void run(Circom_CalcWit *ctx)
{
    solve_10_create(1, 0, ctx, "main", 0);
    solve_10_run(0, ctx);
}
