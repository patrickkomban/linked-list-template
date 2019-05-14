Preamble:   
Author Name:  Patrick Komban

Program:  Student Auditing System

Purpose:  To receive input from a mock student server where some students' data
          are read in, as well as from the command line for each student
          where you can add courses and each courses details with respect to the
          student. These students are stored in a Storage class that holds all the
          Student objects in an array of Student pointers, and each Student
          object contains its own singly-linked list of course pointers.
          Monitor objects help filter out the students who are under-performing
          compared to a GPA threshold or have failed/withdrawn from courses
          compared to a threshold.

Source files: View.cc Monitor.cc GPAMonitor.cc FWMonitor.cc Control.cc CourseList.cc Course.cc Student.cc Storage.cc main.cc
Header files: View.h Monitor.h GPAMonitor.h FWMonitor.h Control.h CourseList.h List.h Course.h Student.h Storage.h StuServer.h defs.h
Data file:    in.txt

Compilation:  make
Launching:    ./sas
  -using the provided text file and then store output: ./sas < in.txt > out.txt
