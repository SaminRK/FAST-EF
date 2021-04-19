import matplotlib as mpl 
import matplotlib.pyplot as plt 
import matplotlib.font_manager as font_manager
import numpy as np

def CreateGanttChartPoint(data):
    """
    Create gantt charts with matplotlib from data
    """ 
    
    # An array of tuples. A tuple has a label and a period.
    task_periods = []

    for ylabel, start_point, end_point in data:
        task_periods.append((ylabel, (start_point, end_point)))

    ilen=len(task_periods)
    pos = np.arange(0.5, ilen*0.5+0.5,0.5)
    
    # Create plot
    fig = plt.figure(figsize=(20,8))
    ax = fig.add_subplot(111)
    
    for i in range(len(task_periods)):
         start_point, end_point = task_periods[i][1]
         ax.barh((i*0.5)+0.5, end_point - start_point, left=start_point, 
                height=0.3, align='center', edgecolor='lightgreen', 
                color='orange', alpha = 0.8)
    
    locsy, labelsy = plt.yticks(pos, [task[0] for task in task_periods])
    
    plt.setp(labelsy, fontsize = 14)
    ax.set_ylim(ymin = -0.1, ymax = ilen*0.5+0.5)
    ax.grid(color = 'g', linestyle = ':')
    ax.set_xlabel('Seconds after start')
    ax.set_title('Gantt chart of different tasks')
  
    labelsx = ax.get_xticklabels()
    plt.setp(labelsx, fontsize=12)
 
    ax.invert_yaxis()
    plt.savefig('gantt.png')
    plt.show()

data = [
    [ 'UE attach procedure', 0, 2.3],
    [ 'Proxy prefetches subs. data', 0.5, 1.1 ],
    [ 'MEC Manager prefetches subs. data', 1.3, 1.7],
    [ 'AMS prefetches state', 1.9, 2.6],
    [ 'User authentication', 2.3, 2.7],
    [ 'State transfer to app instance', 2.7, 2.8],
    [ 'Notify neighbour MECs', 2.8, 3.1]
]

CreateGanttChartPoint(data)