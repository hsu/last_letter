// Dynamic model aggregator class : First pass
class Dynamics
{
	public:
	ModelPlane * parentObj;
	Dynamics(ModelPlane *);
	~Dynamics();
	Aerodynamics * aerodynamics;
	Gravity * gravity;
	Propulsion * propulsion;
	GroundReaction * groundReaction;
	geometry_msgs::Vector3 getForce();
	geometry_msgs::Vector3 getTorque();
};

// Aerodynamics interface class
class Aerodynamics
{
	public:
	ModelPlane * parentObj;
	Aerodynamics(ModelPlane *);
	~Aerodynamics();
	geometry_msgs::Wrench wrenchAero;
	virtual geometry_msgs::Vector3 getForce() = 0;
	virtual geometry_msgs::Vector3 getTorque() = 0;
};

class StdLinearAero : public Aerodynamics
{
	public:
	StdLinearAero(ModelPlane *);
	~StdLinearAero();
	double rho,g,m;
	double c_lift_q,c_lift_deltae,c_drag_q,c_drag_deltae;
	double c,b,s;
	double c_y_0,c_y_b,c_y_p,c_y_r,c_y_deltaa,c_y_deltar;
	double c_l_0, c_l_b, c_l_p, c_l_r, c_l_deltaa, c_l_deltar;
	double c_m_0, c_m_a, c_m_q, c_m_deltae;
	double c_n_0, c_n_b, c_n_p, c_n_r, c_n_deltaa, c_n_deltar;
	double M, alpha0, c_lift_0, c_lift_a0;
	double c_drag_p, oswald, AR;
	geometry_msgs::Vector3 getForce();
	geometry_msgs::Vector3 getTorque();
	//Calculate lift coefficient from alpha
	double liftCoeff(double);
	//Calculate drag coefficient from alpha
	double dragCoeff(double);
	
};