from tkinter import *
import tkinter as tk             # for digital input and output
import subprocess                # for calling c-function in python program

# this is function declaration for saving input
def save():
    text = a.get() + "\n"+b.get() + "\n"+c.get() 
    with open("input.dat", "w") as f:
        f.writelines(text)
        f.close()


master = tk.Tk()
master.geometry("400x300")
master.title("Quadratic function")
label1=tk.Label(text="Please enter input for a,b,c ")


# a,b,c input
# here atext, btext, ctext are for the text messages accompanying them
# here a,b,c is for storing values

atext = tk.Label(text = "a")
atext.grid(row=1, column=0)
a = tk.Entry()
a.grid(row=1, column=1)

btext = tk.Label(text = "b")
btext.grid(row=2, column=0)
b = tk.Entry()
b.grid(row=2, column=1)

ctext = tk.Label(text = "c")
ctext.grid(row=3, column=0)
c = tk.Entry()
c.grid(row=3, column=1)

# save button
button1=tk.Button(master,text="save",command=save,bg="blue")
button1.grid(row=4, column=0)

# this is for calculating our values
def calculate():
    subprocess.call(["gcc","main.c"])    # compiles main.c which in turn also compiles quad.c
    subprocess.call("a.exe")             # since default output of compilation is a.exe , we call that here.


button2=tk.Button(master,text="calculate",command=calculate,bg="blue")
button2.grid(row=5, column=0)


# here we show answer
def show():
    with open("output.res", "r") as f1:
        answer = f1.readlines()
        print(answer) 

button3=tk.Button(master,text="answer",command=show,bg="blue")
button3.grid(row=6, column=0)

mainloop( )










