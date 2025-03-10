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

    int Leetcode_Sol_35(std::vector<int>& nums, int target, int _solution);
    int BinarySearch_35(std::vector<int>& nums, int target);

    int Leetcode_Sol_33(std::vector<int>& nums, int target, int _solution);
    int BinarySearch_33(std::vector<int>& nums, int target);
    // ======= Leetcode Solutions =======

};



extern DLL_API BinarySearch BinarySearchInstance;
