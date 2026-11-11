#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "Empleado.h"
#include "Departamento.h"

// Este es el modelo, agregacion o sea el comprobante apunta a un empleado o sea a uno de nuestros vagones con contenido y a un Departamento
// que existe, aca no los crean muy importante ni los borran, si un comprobante se destruye el empleado o el departamento siguen existiendo
//es lo obvio al dar un recibo con un recibo no destruyes el establecimiento si lo botas, 
//los montos de dinero se guardan aca para hacer el comprobante pero no cambia aunque despues se modifique el salario del Empleado
//o sea puede cambiar y no pasara nada al crear un comprobante se le agrega si se le cambia el salario 
class ComprobantePago {
private:
	int           numero;
	string        periodo;              // esta de aca es el formato o sea el de las fechas un ejemplo es 2026-11
	Empleado*     empleado;             // agregación (no se borra en este lugar se borra en otro documento )
	Departamento* departamento;         // agregación (no se borra en este lugar se borra en otro documento )
	int           horasExtra;
	int           cantidadBono;
	double        salarioBase;
	double        montoHorasExtra;
	double        bonificacion;
	double        deduccionSalud;       // CCSS: Seguro de Enfermedad y Maternidad
	double        deduccionPensiones;   // CCSS: Invalidez Vejez y Muerte
	double        deduccionBanco;       // Banco Popular
	string         estado;              // aca se ve si esta PENDIENTE O PAGADO 
	
public:
	ComprobantePago(int num, string per, Empleado* emp, Departamento* dep);
	~ComprobantePago();
	
	int           getNumero();
	string        getPeriodo();
	Empleado*     getEmpleado();
	Departamento* getDepartamento();
	int           getHorasExtra();
	int           getCantidadBono();
	double        getSalarioBase();
	double        getMontoHorasExtra();
	double        getBonificacion();
	double        getDeduccionSalud();
	double        getDeduccionPensiones();
	double        getDeduccionBanco();
	string        getEstado();
	
	void setIngresos                (int horas, int cantBono, double base, double extras, double bono);
	void setDeducciones             (double salud, double pensiones, double banco);
	void setEstado                  (string est);
	
	double getSalarioBruto();
	double getTotalDeducciones();
	double getSalarioNeto();
	bool   estaPagado();
	
	string toString();  // aca se da un desglose completo de el comprobante 
	string resumen();   // aca se da una sola linea para todos los listados 
};

#endif
