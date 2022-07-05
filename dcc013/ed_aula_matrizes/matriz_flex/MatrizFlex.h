class MatrizFlex
{
public:
    MatrizFlex(int li, int lf, int ci, int cf);
    ~MatrizFlex();
    float get(int i, int j);
    void set(int i, int j, float val);

private:
    float *vet; // representacao linear da matriz
    int m, n;   // numero de linhas e colunas
    int lil;    // limite inicial da linha
    int lic;    // limite inicial da coluna
    int lfl;    // limite final da linha
    int lfc;    // limite final da coluna
    int detInd(int linha, int coluna);
};