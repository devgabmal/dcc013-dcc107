#include <iostream>
#include "NoArv.h"

using namespace std;

NoArv::NoArv() {}

NoArv::~NoArv() {}

void NoArv::setEsq(NoArv *p) { esq = p; }

void NoArv::setInfo(int val) { info = val; }

void NoArv::setDir(NoArv *p) { dir = p; }

NoArv *NoArv::getEsq() { return esq; }

int NoArv::getInfo() { return info; }

NoArv *NoArv::getDir() { return dir; }