package views;



import java.util.ArrayList;
import java.util.Scanner;

import Model.Admin;
import Model.Employee;
import Model.HR;
import Model.SalesManager;
import controller.EmployeeDAO;



public class MainEmp {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		EmployeeDAO dao = new EmployeeDAO();
		ArrayList<Employee> employees=null;
		int choice;
		do {
			System.out.println("\n===== Employee Management Menu =====");
			System.out.println("1. Add Employee");
			System.out.println("2. Search Employee");
			System.out.println("3. Update Employee");
			System.out.println("4. Delete Employee");
			System.out.println("5. Display All Employees");
			System.out.println("6. Calculate Salary of Each Employee");
			System.out.println("0. Exit");
			System.out.print("Enter your choice: ");
			choice = sc.nextInt();

			switch (choice) {
			case 1:
				System.out.println("Enter Employee Type  ");
				System.out.println("1 to add HR:");
				System.out.println("2 to add Admin");
				System.out.println("3 to add Salesmanager");
				int type = sc.nextInt();

				System.out.print("Enter ID: ");
				int id = sc.nextInt();
				sc.nextLine();
				System.out.print("Enter Name: ");
				String name = sc.nextLine();
				System.out.print("Enter Base Salary: ");
				double salary = sc.nextDouble();

				if (type == 1) {
					System.out.print("Enter Commission: ");
					double comm = sc.nextDouble();
					dao.addEmployee(new HR(id, name, salary, comm));
					System.out.println("HR added successfully!");
				} else if (type == 2) {
					System.out.print("Enter Allowance: ");
					double allowance = sc.nextDouble();
					dao.addEmployee(new Admin(id, name, salary, allowance));
					System.out.println("Admin added successfully!");
				} else if (type == 3) {
					System.out.print("Enter Target: ");
					int target = sc.nextInt();
					System.out.print("Enter Incentive per Target: ");
					double incentive = sc.nextDouble();
					dao.addEmployee(new SalesManager(id, name, salary, target, incentive));
					System.out.println("Sales Manager added successfully!");
				} else {
					System.out.println("Invalid Type!");
				}
				break;

			case 2:
				System.out.print("Enter ID to search: ");
				id = sc.nextInt();
				Employee e = dao.searchEmployeeById(id);
				if (e != null)
					System.out.println("Found: " + e);
				else
					System.out.println("Employee not found.");
				break;

			case 3:
				System.out.print("Enter ID to update: ");
				id = sc.nextInt();
				System.out.print("Enter New Salary: ");
				salary = sc.nextDouble();
				if (dao.updateEmployee(id, salary))
					System.out.println("Updated successfully!");
				else
					System.out.println("Employee not found.");
				break;

			case 4:
				System.out.print("Enter ID to delete: ");
				id = sc.nextInt();
				if (dao.deleteEmployee(id))
					System.out.println("Deleted successfully!");
				else
					System.out.println("Employee not found.");
				break;

			case 5:
				employees = dao.getAllEmployee();
				break;

			case 6:
				employees = dao.getAllEmployee();
				for (int i = 0; i < employees.size(); i++) {
					System.out.println(employees.get(i).getName() + " → Final Salary: " + employees.get(i).calculateSalary());
				}
				break;

			case 0:
				System.out.println("Exiting... Goodbye!");
				break;

			default:
				System.out.println("Invalid choice! Try again.");
			}
		} while (choice != 0);

		sc.close();
	}
}
