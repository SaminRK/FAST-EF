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
    [ 'UE: attach', 0, 1.395],
    [ 'UE: user authentication', 1.495, 2.324],
    [ 'UE: load initial state', 2.325, 2.986],
    [ 'MEC: Fetch subscription data', 0.495, 0.851],
    [ 'MEC: Fetch state', 0.502, 0.805],
]

CreateGanttChartPoint(data)