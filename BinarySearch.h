#pragma once

#define Build_DLL

#ifdef Build_DLL 
#define DLL_API _declspec(dllexport)
#else 
#define DLL_API _declspec(dllimport)
#endif // BuildDLL _declspec(DLLExport)

#include <string>
#include <iostream>
#include <vector>       // �Y�����ܼƥΨ� std::vector
#include <map>          // �Y�� std::map �ܼ�
#include <unordered_map>// �Y�� std::unordered_map �ܼ�

class BinarySearch {
private:
    int* data;  // ���]��Ʀ����O����

public:
    // �w�]�غc��
    BinarySearch();

    // �a�Ѽƫغc��
    BinarySearch(int value);

    // �Ѻc��
    ~BinarySearch();

    // ��k�G�]�w��
    void setData(int value);

    // ��k�G���o��
    int getData() const;

    // ��ܸ��
    void display() const;

    // ======= Leetcode Solutions =======
    int Leetcode_Sol_704(std::vector<int>& nums, int target, int _solution);
    int BinarySearch_704(std::vector<int>& nums, int target);

    int Leetcode_Sol_35(std::vector<int>& numsD, int target, int _solution);
    int BinarySearch_35(std::vector<int>& nums, int target);

    int Leetcode_Sol_153(std::vector<int>& nums, int _solution);
    int BinarySearch_153(std::vector<int>& nums);

    std::vector<int> Leetcode_Sol_34(std::vector<int>& nums, int target, int _solution);//*****
    std::vector<int> BinarySearch_34(std::vector<int>& nums, int target);
    std::vector<int> DoubleBinarySearch_34(std::vector<int>& nums, int target);//*****
    std::vector<int> Mylower_bound_34(std::vector<int>& nums, int target);//*****
    std::vector<int> stdlower_bound_34(std::vector<int>& nums, int target);

    int Leetcode_Sol_33(std::vector<int>& numsD, int target, int _solution);
    int DoubleBinarySearch_33(std::vector<int>& nums, int target);
    int OnceBinarySearch_33(std::vector<int>& nums, int target);//*****(�۷��Trapping Rain Water���D)


    // ======= Leetcode Solutions =======

};



extern DLL_API BinarySearch BinarySearchInstance;
