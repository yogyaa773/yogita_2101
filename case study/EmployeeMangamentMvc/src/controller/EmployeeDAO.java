package controller;



import java.util.ArrayList;

import Model.Admin;
import Model.Employee;
import Model.HR;
import Model.SalesManager;


public class EmployeeDAO {
	
	
	static ArrayList<Employee> employees=new ArrayList<Employee>();
	static {
		
		employees.add( new HR(101, "Swara", 70000,4000));
		employees.add( new HR(102, "Shambhu", 78000, 6500));
		employees.add( new HR(103, "vedant", 90000, 9000));
		employees.add( new SalesManager(201, "tanisha", 50000, 10, 3000));
		employees.add( new SalesManager(202, "yogita", 28000, 12, 5000));
		employees.add( new SalesManager(203, "yogesh", 65000, 16, 9000));
		employees.add( new Admin(301, "suyash", 90000, 90000));
		employees.add( new Admin(302, "chaitu", 88000, 7500));
		employees.add( new Admin(303, "rutu", 82000, 1000));
		employees.add( new Admin(304, "omkar", 55000, 1200));
	}
	public boolean addEmployee(Employee e) {
	       return employees.add(e);
    }
	
    public Employee searchEmployeeById(int id) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getId() == id) {
                return employees.get(i);
            }
        }
        return null;
    }

  
    public boolean updateEmployee(int id, double newSalary) {
        Employee emp = searchEmployeeById(id);
        if (emp != null) {
            emp.setSalary(newSalary);
            return true;
        }
        return false;
    }

    public boolean deleteEmployee(int id) {
    	 Employee emp = searchEmployeeById(id);
         if (emp != null) {
        	 employees.remove(emp);
             return true;
         }
         return false;
    }
 
    

    public  ArrayList<Employee> getAllEmployee() {
        
        return employees;
    }
   

	
}

