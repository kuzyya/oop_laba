#pragma once
#include <iostream>
#include <vector>
using namespace std;

class mathVector {
private:
    vector <int> V;
public:
    mathVector() {
        vector <int> V();
    }

    mathVector(vector<int> A)
    {
        V = A;
    }

    ~mathVector()
    {
        V.~vector();
    }

    void insert(int a) {
        V.push_back(a);
    }

    mathVector operator + (mathVector const& obj) {
        if (V.size() > obj.V.size())
        {
            vector <int> res = V;
            for (int i = 0; i < obj.V.size(); i++)
            {
                res[i] = V[i] + obj.V[i];
            }
            return res;
        }
        else
        {
            vector <int> res = obj.V;
            for (int i = 0; i < V.size(); i++)
            {
                res[i] = V[i] + obj.V[i];
            }
            return res;
        }
    }

    mathVector operator - (mathVector const& obj) {
        if (V.size() > obj.V.size())
        {
            vector <int> res = V;
            for (int i = 0; i < obj.V.size(); i++)
            {
                res[i] = V[i] - obj.V[i];
            }
            return res;
        }
        else
        {
            vector <int> res = obj.V;
            for (int i = 0; i < V.size(); i++)
            {
                res[i] = V[i] - obj.V[i];
            }
            for (int i = V.size(); i < obj.V.size(); i++)
            {
                res[i] -= 2 * obj.V[i];
            }
            return res;
        }
    }

    int operator * (mathVector const& obj) {
        int dot_product = 0;
        for (int i = 0; i < min(V.size(), obj.V.size()); i++)
            dot_product += V[i] * obj.V[i];
        return dot_product;
    }

    mathVector operator * (int a) {
        for (int i = 0; i < V.size(); i++)
            V[i] *= a;
        return V;
    }

    bool operator == (mathVector const& obj)
    {
        if (obj.V.size() != V.size()) return false;
        for (int i = 0; i < V.size(); i++)
            if (V[i] != obj.V[i]) return false;
        return true;
    }

    friend ostream& operator <<(ostream& out, const mathVector& obj)
    {
        out << "(";
        for (int i = 0; i < obj.V.size() - 1; i++)
        {
            out << obj.V[i] << ",";
        }
        out << obj.V[obj.V.size() - 1] << ")";
        return out;
    }
};
