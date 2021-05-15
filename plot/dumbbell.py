import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import numpy as np
import matplotlib.patches as mpatches

# Func to draw line segment
def newline(p1, p2, color):
    ax = plt.gca()
    l = mlines.Line2D([p1[0],p2[0]], [p1[1],p2[1]], linewidth=5, color=color)
    ax.add_line(l)
    return l

def draw_dumbbell(data, ax, color, offset):
    y = np.array(data['index']) + offset
    # Points
    ax.scatter(y=y, x=data['start'], s=150, color=color, alpha=0.7)
    ax.scatter(y=y, x=data['end'], s=150, color=color, alpha=0.7)

    # Line Segments
    for i, p1, p2 in zip(y, data['start'], data['end']):
        newline([p1, i], [p2, i], color)

def main():
    labels = ['without optimizations', 'with optimizations']
    colors = ['blue', 'green']

    without_opt = {
      'index': [5, 4, 3, 2, 1, 0],
      'start': [0, 1.357, 1.426, 3.382, 3.620, 3.918],
      'end': [1.356, 3.381, 1.747, 4.304, 3.917, 3.969]
    }
    
    with_opt = {
      'index': [5, 4, 3, 2, 1, 0],
      'start': [0, 1.396, .495, 2.225, .502, 2.551],
      'end': [1.395, 2.224, .816, 2.886, .799, 2.602]
    }

    # Figure and Axes
    fig, ax = plt.subplots(1,1, figsize=(14,8))

    draw_dumbbell(without_opt, ax, colors[0], 0.05)
    draw_dumbbell(with_opt, ax, colors[1], -0.05)

    # Decoration
    ax.set(xlim=(0, 4.5), xlabel='Time after UE attach starts (s)', ylabel='Stages')
    ax.set_yticks([5, 4, 3, 2, 1, 0])
    ax.set_yticklabels(['U1', 'U2', 'M1', 'U3', 'M2', 'M3'])
    ax.grid(linestyle = ':')

    patch0 = mpatches.Patch(color=colors[0], label=labels[0])
    patch1 = mpatches.Patch(color=colors[1], label=labels[1])
    ax.legend(handles=[patch0, patch1], fontsize=15)

    for item in ([ax.title, ax.xaxis.label, ax.yaxis.label] +
             ax.get_xticklabels() + ax.get_yticklabels()):
        item.set_fontsize(20)
    
    
    plt.savefig('dumbbell.png')
    plt.savefig('dumbbell.svg')
    plt.show()

if __name__ == "__main__":
    main()

