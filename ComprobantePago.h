#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "Empleado.h"
#include "Departamento.h"

// este es el modelo, agregacion osea el comporbante apinta a un empleado osea al pasajero que va dentro de un vagon y a un Departamento
// que existe, aca no los crean muy importante ni los borran, si un comporbante se destruye el empleado o el departamento siguen excistirndo
//es lo obio al dar un resivo con un reviso no deastruyes el establecimiento si lo votas, 
//los monton de dinero se guardan aca para hacer el comprobante pero no cambia aunque despiues se modifique el salario del Empleado
//osea el comprobante ya creado conserva sus montos y el salario nuevo solo se usa en los comprobantes siguientes 
class ComprobantePago {
private:
	int           numero;
	string        periodo;              // esta de aca es el formato osea el de las fechas un ejemplo es 2026-11
	Empleado*     empleado;             // agregación (no se borra en este lugra se borra en otro documento )
	Departamento* departamento;         // agregación (no se borra en este lugra se borra en otro documento )
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
	
	string toString();  // acxa se da un desaglose completo de el comprobante 
	string resumen();   // aca se da una sola linea para todos los listados 
};

#endif
