#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Perceptron.h"
#include "PrintChart.h"
using namespace std;

double ** funXOR() {
    double ** d = new double*[4];
    for(int i = 0; i < 4; i++) {
        d[i] = new double[3];
    }
    d[0][0] = 0.0;d[0][1] = 0.0;d[0][2] = 0;
    d[1][0] = 0.0;d[1][1] = 1.0;d[1][2] = 1;
    d[2][0] = 1.0;d[2][1] = 0.0;d[2][2] = 1;
    d[3][0] = 1.0;d[3][1] = 1.0;d[3][2] = 0;
    return d;
}
double ** fun(int n) {
    double **d = new double*[n];
    for(int i = 0; i < n ; i++) {
        d[i] = new double[2];
        d[i][0] = ((double)rand() / (RAND_MAX)) * n;
        d[i][1] = (d[i][0] >= n/2) ? 1 : 0;
    }
    return d;
}
double** fun2(int n) {
    double **d = new double*[n];
    for(int i = 0; i < n; i++) {
        d[i] = new double[3];
        d[i][0] = ((double)rand()/(RAND_MAX)) * 10;
        d[i][1] = ((double)rand()/(RAND_MAX)) * 10;
        d[i][2] = (d[i][1] - (1.5 * d[i][0]) >= 0) ? 1 : 0;
    }
    return d;
}

void printChart(sf::RenderWindow &window, double** dane, int size) {

    sf::CircleShape point(1);
    for(int i = 0; i < size; i++) {
        if(dane[i][2] == 0) {
            point.setFillColor(sf::Color(255,255,255));
        } else {
            point.setFillColor(sf::Color(0,255,0));
        }
        point.setPosition((float)dane[i][0],(float)dane[i][1]);
        window.draw(point);
    }
    window.clear();
    window.display();
}

int main()
{
    srand (time(NULL));
    double** dane = fun2(10);
    Perceptron *p = new Perceptron(2);
    p->trenujNeutron(dane,10);
    cout << "[Perceptron]: Teraz możesz mnie przepytać!" << endl;
     double p1;
     double p2;
     for(int i = 0; i < 10; i++) {
         cin >> p1;
         cin >> p2;
         p->odpowiedz2(p1,p2);
     }

    return 0;
}
