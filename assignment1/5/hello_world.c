/*
 *  Assignment 1
 *  Setup & LKM Introduction
 *
 *  Requirements:
 *      a) Use printk to perform any output. This output should use the KERN_INFO
 *          log level.
 *      b) Your module should output welcome and goodbye messages when mod.ko is
 *          loaded and unloaded, respectively.
 *      c) Your module should contain a function print_nr_procs(). This function
 *          should out- put the number of processes in the system. Use the
 *          for_each_process macro (sched.h) to get the number of processes.
 *      d) After the welcome message,this module should call print_nr_procs()
 *          when loaded.
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

void print_nr_procs(void){
    struct task_struct *task_list;
    int process_counter = 0;
    for_each_process(task_list) {
        ++process_counter;
    }
    printk(KERN_INFO "The number of process : %d\n", process_counter);

    return;
}

int init_module(void){
    printk(KERN_INFO "Hello world\n");

    print_nr_procs();

    return 0;
}

void cleanup_module(void){
    printk(KERN_INFO "Goodbye world\n");

    return;
}

