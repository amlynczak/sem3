#pragma once

/**
 * @brief oblicza silnie w sposob iteracyjny
 * 
 * @param n jaka liczbe "silniujemy"
 * @return int zwraca wynik
 */
int silnia_i(int n){
    int wynik = 1;
    for(int i=2; i<=n; i++){
        wynik = wynik * i;
    }
    return wynik;
}

/**
 * @brief oblicza silnie w sposob rekurencyjny
 * 
 * @param n liczba, ktora podnosimy do silni
 * @return int zwraca wynik
 */
int silnia_r(int n){
    int wynik = n;
    if(wynik == 0) return 1;
    wynik = wynik * silnia_r(n-1);
    
    return wynik;
}


/**
 * @brief wylicza dwumian newtona
 * 
 * @param m liczba 1
 * @param n liczba 2
 * @return int zwraca poprawny wynik
 */
int newton(int m, int n){
    int wynik;
    wynik = (silnia_i(m))/((silnia_i(n))*(silnia_i(m-n)));
    return wynik;
}