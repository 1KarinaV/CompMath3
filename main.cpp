#include <iostream>
#include <math.h>

using namespace std;
static double func1(double x);
static double func2(double x);
static double func3(double x);
static double func4(double x);
static double func5(double x);
static double func6(double x);

double Simpson(double func(double),double a, double b, double eps, int n) {
    const double h = (b-a)/n;
    double k1 = 0, k2 = 0;
    for(int i = 1; i < n; i += 2) {
        k1 += func(a + i*h);
        k2 += func(a + (i+1)*h);
    }
    return h/3*(func(a) + 4*k1 + 2*k2);
}

int main(){
    double a,b, s1, s, n, eps;
    int choose=0;

    cout << "Выберите функцию: "<< endl;
    cout << "(0) y=x"<< endl;
    cout << "(1) y=x^2"<< endl;
    cout << "(2) y=2x+1/(sqrt(x))+1/16"<< endl;
    cout << "(3) y=sqrt(x)"<< endl;
    cout << "(4) y=sin(x)/x"<< endl;
    cout << "(5) y=1/x"<< endl;
    cin >> choose;
    if(choose==0){
    cout << "Введите нижний предел интегрирования: "<< endl;
    cin >> a;
    cout << "Введите верхний предел интегрирования: "<< endl;
    cin >> b;
    cout << "Введите количество элементарных промежутков: " << endl;
    cin >> n;

    cout << "Введите точность: " << endl;
    cin >> eps;
    s1 = Simpson(func1, a, b, eps, n); //первое приближение для интеграла
        do {
            s = s1;     //второе приближение
            n = 2 * n;  //увеличение числа шагов в два раза,
            //т.е. уменьшение значения шага в два раза
            s1 = Simpson(func1, a, b,eps, n);
        }
        while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
        cout << "\nИнтеграл = " << s1 << endl;
        cout<< "\nОшибка = " <<fabs(s1 - s)<<endl; //ошибка, которая позволила закончить итерации
    }
    if(choose==1){
        cout << "Введите нижний предел интегрирования: "<< endl;
        cin >> a;
        cout << "Введите верхний предел интегрирования: "<< endl;
        cin >> b;
        cout << "Введите количество элементарных промежутков: " << endl;
        cin >> n;

        cout << "Введите точность: " << endl;
        cin >> eps;
        s1 = Simpson(func2, a, b, eps, n);
        do {
            s = s1;
            n = 2 * n;
            s1 = Simpson(func2, a, b, eps, n);
        }
        while (fabs(s1 - s) > eps);
        cout << "\nИнтеграл = " << s1 << endl;
        cout<< "\nОшибка = " <<fabs(s1 - s)<<endl;
    }
    if(choose==2){
        cout << "Введите нижний предел интегрирования: "<< endl;
        cin >> a;
        cout << "Введите верхний предел интегрирования: "<< endl;
        cin >> b;
        cout << "Введите количество элементарных промежутков: " << endl;
        cin >> n;

        cout << "Введите точность: " << endl;
        cin >> eps;
        if (b <= 0 || a <= 0){
            cout<<"Невозможно поситать интеграл. Выход за пределы ОДЗ";
            exit(1);
        }
        else
            s1 = Simpson(func3, a, b, eps, n);
        do {
            s = s1;
            n = 2 * n;
            s1 = Simpson(func3, a, b, eps, n);
        }
        while (fabs(s1 - s) > eps);
        cout << "\nИнтеграл = " << s1 << endl;
        cout<< "\nОшибка = " <<fabs(s1 - s)<<endl;
    }
    if(choose==3){
        cout << "Введите нижний предел интегрирования: "<< endl;
        cin >> a;
        cout << "Введите верхний предел интегрирования: "<< endl;
        cin >> b;
        cout << "Введите количество элементарных промежутков: " << endl;
        cin >> n;

        cout << "Введите точность: " << endl;
        cin >> eps;
        if (b < 0 || a < 0){
            cout<<"Невозможно вычислить интеграл. Выход за пределы ОДЗ";
            exit(1);
        }
        else
            s1 = Simpson(func4, a, b, eps, n);
        do {
            s = s1;
            n = 2 * n;
            s1 = Simpson(func4, a, b, eps, n);
        }
        while (fabs(s1 - s) > eps);
        cout << "\nИнтеграл = " << s1 << endl;
        cout<< "\nОшибка = " <<fabs(s1 - s)<<endl;
    }
    if(choose==4){
        cout << "Введите нижний предел интегрирования: "<< endl;
        cin >> a;
        cout << "Введите верхний предел интегрирования: "<< endl;
        cin >> b;
        cout << "Введите количество элементарных промежутков: " << endl;
        cin >> n;

        cout << "Введите точность: " << endl;
        cin >> eps;
        const double h = (b-a)/n;
        double k1 = 0, k2 = 0;
        for(int i = 1; i < n; i += 2) {
            double value=a+i*h;
            if(value==0){
                value+=0.00001;
            }
            k1 += func5(value);
            value=a+(i+1)*h;
            if(value==0){
                value+=0.00001;
            }
            k2 += func5(value);
        }
        if (a==0){
            a+=0.000001;
        }
        if (b==0){
            b+=0.000001;
        }
        s1 = (h/3)*(func5(a) + 4*k1 + 2*k2);
            do {
                k1 = 0, k2 = 0;
                s = s1;
                n = 2 * n;
                const double h = (b-a)/n;
                for(int i = 1; i < n; i += 2) {
                    double value=a+i*h;
                    if(value==0){
                        value+=0.00001;
                    }
                    k1 += func5(value);
                    value=a+(i+1)*h;
                    if(value==0){
                        value+=0.00001;
                    }
                    k2 += func5(value);
                }
                if (a==0){
                    a+=0.000001;
                }
                if (b==0){
                    b+=0.000001;
                }
                s1= (h/3)*(func5(a) + 4*k1 + 2*k2);
            }
            while (fabs(s1 - s) > eps);
            cout << "\nИнтеграл = " << s1 << endl;
            cout<< "\nОшибка = " <<fabs(s1 - s)<<endl;
            cout<< "\nПри вычислении была устранена точка разрыва";
            exit(1);
        }
    if(choose==5){
        cout << "Введите нижний предел интегрирования: "<< endl;
        cin >> a;
        cout << "Введите верхний предел интегрирования: "<< endl;
        cin >> b;
        cout << "Введите количество элементарных промежутков: " << endl;
        cin >> n;

        cout << "Введите точность: " << endl;
        cin >> eps;
        if (b == 0 || a == 0 || (a < 0 && b > 0) || (b < 0 && a > 0)){
            cout<<"\nНевозможно вычислить, неустранимый разрыв второго рода";
            exit(1);
        }
        s1 = Simpson(func6, a, b, eps, n);
        do {
            s = s1;
            n = 2 * n;
            s1 = Simpson(func6, a, b, eps, n);
        }
        while (fabs(s1 - s) > eps);
        cout << "\nИнтеграл = " << s1 << endl;
        cout<< "\nОшибка = " <<fabs(s1 - s)<<endl;

    }

}

static double func1(double x) //x
{
    return x;
}

static double func2(double x) //x^2
{
    return pow(x, 2);
}

static double func3(double x) //2x+1/(sqrt(x))+1/16
{
    return 2*x+1/(sqrt(x))+1/16;
}

static double func4(double x) //sqrt(x)
{
    return sqrt(x);
}

static double func5(double x) // sin(x)/x
{
    return sin(x)/x;
}

static double func6(double x) //1/x
{
    return 1/x;
}
