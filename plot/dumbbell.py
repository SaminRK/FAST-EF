import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import numpy as np

# Func to draw line segment
def newline(p1, p2, color):
    ax = plt.gca()
    l = mlines.Line2D([p1[0],p2[0]], [p1[1],p2[1]], color=color)
    ax.add_line(l)
    return l

def draw_dumbbell(data, ax, color, offset):
    y = np.array(data['index']) + offset
    # Points
    ax.scatter(y=y, x=data['start'], s=50, color=color, alpha=0.7)
    ax.scatter(y=y, x=data['end'], s=50, color=color, alpha=0.7)

    # Line Segments
    for i, p1, p2 in zip(y, data['start'], data['end']):
        newline([p1, i], [p2, i], color)

def main():
    with_opt = {
      'index': [4,3,2,1,0],
      'start': [0, 1.495, 2.325, .495, .502],
      'end': [1.395, 2.324, 2.986, .851, .805]
    }

    without_opt = {
      'index': [4,3,2,1,0],
      'start': [0, 1.456, 3.482, 1.526, 3.720],
      'end': [1.356, 3.481, 4.404, 1.812, 4.091]
    }

    # Figure and Axes
    fig, ax = plt.subplots(1,1,figsize=(14,14), facecolor='#f7f7f7', dpi= 80)

    draw_dumbbell(with_opt, ax, 'blue', 0.1)
    draw_dumbbell(without_opt, ax, 'green', -0.1)

    ax.set(xlabel='Time after UE attach start (s)')
    ax.set_yticks([4, 3, 2, 1, 0])
    ax.set_yticklabels(['U1', 'U2', 'U3', 'M1', 'M2'])
    ax.grid(linestyle = ':')
    
    plt.show()

if __name__ == "__main__":
    main()

