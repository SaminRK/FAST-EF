import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

def main():
    state_transfer_sizes = ['10 KB', '1 MB', '10 MB']

    data = [[0.885, 5.23, 33.28], [0.07, 0.341, 2.713], [0.034, 0.066, 0.234]]
    colors = ['tab:blue', 'tab:orange', 'tab:green']
    labels = ['Cloud', 'Without prefetching', 'With prefetching']
    hatches = ['//', '\\\\', '---']

    X = np.arange(3)

    mpl.rcParams.update({'font.size': 12})

    # ax1 top, ax2 bottom
    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)
    fig.subplots_adjust(hspace=0.08)

    ax1_bars = []
    for i in range(3):
        b = ax1.bar(X + i * 0.25, data[i], fill=False, facecolor = None, edgecolor = colors[i], 
            width = 0.25, hatch = hatches[i], label=labels[i])
        ax1_bars.append(b)
    
    bar1 = ax1_bars[0]
    bar2 = ax1_bars[1]
    bar3 = ax1_bars[2]

    ax2_bars = []
    for i in range(3):
        b = ax2.bar(X + i * 0.25, data[i], fill=False, facecolor = None, edgecolor = colors[i], 
            width = 0.25, hatch = hatches[i], label=labels[i])
        ax2_bars.append(b)

    AX2_MIN_LIMIT = 0
    AX2_MAX_LIMIT = 0.5
    AX1_MIN_LIMIT = 0.5 
    AX1_MAX_LIMIT = 37

    ax2.set_ylim(AX2_MIN_LIMIT, AX2_MAX_LIMIT)
    ax1.set_ylim(AX1_MIN_LIMIT, AX1_MAX_LIMIT)  

    # Add counts above the two bar graphs
    for rect in bar1 + bar2 + bar3:
        height = rect.get_height()
        if height > AX1_MIN_LIMIT:
            ax1.text(rect.get_x() + rect.get_width()/2.0, height, f'{height}',  ha='center', va='bottom')
        else:
            ax2.text(rect.get_x() + rect.get_width()/2.0, height, f'{height}',  ha='center', va='bottom')

    ax1.set_yticks([AX1_MIN_LIMIT, 10, 20, 30])
    ax1.set_xticks([])
    plt.xticks(ticks=np.arange(3) + 0.33 / 2, labels=state_transfer_sizes)
    
    ax2.text(-0.1, 1, 'Latency(s)', rotation=90, 
        verticalalignment='center', horizontalalignment='right', 
        transform=ax2.transAxes)
    plt.xlabel('State sizes')

    ax1.legend()

    plt.savefig('state_transfer_sizes.png')
    plt.savefig('state_transfer_sizes.svg')
    plt.show()

if __name__ == '__main__':
    main()