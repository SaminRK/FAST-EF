import matplotlib.pyplot as plt
import numpy as np
import matplotlib.patches as mpatches

def draw_gantt(data, ax, color):
    for i in range(len(data['start'])):
         start_point = data['start'][i]
         end_point = data['end'][i]
         ax.barh(data['index'][i], end_point - start_point, left=start_point, 
                height=0.9, align='center', 
                color=color)
    
    ax.grid(axis="x", linestyle = ':')
    ax.set_axisbelow(True)

def set_font(ax, font_size):
    for item in ([ax.title, ax.xaxis.label, ax.yaxis.label] +
             ax.get_xticklabels() + ax.get_yticklabels()):
        item.set_fontsize(font_size)

def main():
    labels = ['Without optimizations', 'With optimizations']
    colors = ['skyblue', 'tab:orange']

    without_opt = {
      'index': [5, 4, 3, 2, 1, 0],
      'start': [0, 1.357, 1.426, 3.482, 3.720, 4.018],
      'end': [1.356, 3.481, 1.747, 4.404, 4.017, 4.069]
    }
    
    with_opt = {
      'index': [5, 4, 3, 2, 1, 0],
      'start': [0, .495, .502, 1.396,  2.325, 2.651],
      'end': [1.395, .816, .799, 2.324, 2.986, 2.702]
    }

    # ax1 top, ax2 bottom
    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True, figsize=(14,8))
    fig.subplots_adjust(hspace=0.05)

    draw_gantt(without_opt, ax1, colors[0])
    draw_gantt(with_opt, ax2, colors[1])

    # Decoration
    ax1.set_yticks([5, 4, 3, 2, 1, 0])
    ax2.set_yticks([5, 4, 3, 2, 1, 0])
    ax1.set_xticks([])
    plt.xticks(ticks=np.arange(10) * 0.5)

    plt.xlabel('Time after UE attach starts (s)')
    ax2.text(-0.06, 1, 'Stages', rotation=90, 
        verticalalignment='center', horizontalalignment='right', 
        transform=ax2.transAxes, fontsize=20)
    
    ax1.set_yticklabels(['U1', 'U2', 'M1', 'U3', 'M2', 'M3'])
    ax2.set_yticklabels(['U1', 'M1', 'M2', 'U2', 'U3', 'M3'])

    patch0 = mpatches.Patch(color=colors[0], label=labels[0])
    patch1 = mpatches.Patch(color=colors[1], label=labels[1])
    ax1.legend(handles=[patch0, patch1], fontsize=15)

    set_font(ax1, 20)
    set_font(ax2, 20)
    
    plt.savefig('time_period.png')
    plt.savefig('time_period.svg')
    plt.show()

if __name__ == "__main__":
    main()

