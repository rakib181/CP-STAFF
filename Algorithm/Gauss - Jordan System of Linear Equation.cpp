#include<bits/stdc++.h>
using namespace std;

struct info{
   double eqn[100];
   double res;
}matrix[100];

bool no_sol = false;

void forming_Gaussian(int n){
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            double multiple = matrix[j].eqn[i] / matrix[i].eqn[i];
             if(matrix[i].eqn[i] == 0){
                 no_sol = true;
                 break;
             }
            for(int k = 1; k <= n; k++){
                matrix[j].eqn[k] -= matrix[i].eqn[k] * multiple;
            }
            matrix[j].res = matrix[j].res - matrix[i].res * multiple;
        }
    }
}
void forming_Jordan(int n){
    for(int i = n; i >= 1; i--){
        for(int j = i - 1; j >= 1; j--){
            double multiple = matrix[j].eqn[i] / matrix[i].eqn[i];
            if(matrix[i].eqn[i] == 0){
                no_sol = true;
                break;
            }
            for(int k = n; k >= 1; k--){
                matrix[j].eqn[k] -= matrix[i].eqn[k] * multiple;
            }
            matrix[j].res = matrix[j].res - matrix[i].res * multiple;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i].eqn[j];
        }
        cin >> matrix[i].res;
    }
    forming_Gaussian(n);
    if(no_sol){
        cout << "There is no uniqe soln !" << '\n';
    }else{
        forming_Jordan(n);
        if(no_sol){
            cout << "There is no uniqe soln !" << '\n';
        }else{
            for(int i = 1; i <= n; i++){
                cout <<"Equation -> "<<"("<< i<<")"<< " = " << matrix[i].res / matrix[i].eqn[i] << '\n';
            }
            cout << '\n';
        }
    }
    return 0;
}
