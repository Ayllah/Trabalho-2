#include "entidades.h"

bool Disponibilidade :: comparaDisponibilidade (Disponibilidade disponibilidadeX, Disponibilidade disponibilidadeY) const{
    Data dataInicio_DisponibilidadeX = disponibilidadeX.getDataInicioDisponibilidade();
    Data dataInicio_DisponibilidadeY = disponibilidadeY.getDataInicioDisponibilidade();

    if (Data :: comparaDatas(dataInicio_DisponibilidadeX, dataInicio_DisponibilidadeY) == -1){
        return true;
    }
    else if(Data :: comparaDatas(dataInicio_DisponibilidadeX, dataInicio_DisponibilidadeY) == 1){
        return false;
    }
}