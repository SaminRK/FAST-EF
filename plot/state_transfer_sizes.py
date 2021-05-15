import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

def main():
    state_transfer_sizes = ['10 KB', '1 MB', '10 MB']

    data = [[0.885, 5.23, 33.28], [0.07, 0.341, 2.713], [0.034, 0.066, 0.234]]
    labels = ['cloud', 'without prefetching', 'with prefetching']

    X = np.arange(3)

    mpl.rcParams.update({'font.size': 12})

    # ax1 top, ax2 bottom
    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)
    fig.subplots_adjust(hspace=0.08)

    bar1 = ax1.bar(X + 0.00, data[0], color = 'tab:blue', width = 0.25, label=labels[0])
    bar2 = ax1.bar(X + 0.25, data[1], color = 'tab:orange', width = 0.25, label=labels[1])
    bar3 = ax1.bar(X + 0.50, data[2], color = 'tab:green', width = 0.25, label=labels[2])

    bar4 = ax2.bar(X + 0.00, data[0], color = 'tab:blue', width = 0.25, label=labels[0])
    bar5 = ax2.bar(X + 0.25, data[1], color = 'tab:orange', width = 0.25, label=labels[1])
    bar6 = ax2.bar(X + 0.50, data[2], color = 'tab:green', width = 0.25, label=labels[2])

    AX2_MIN_LIMIT = 0
    AX2_MAX_LIMIT = 0.5
    AX1_MIN_LIMIT = 0.5 
    AX1_MAX_LIMIT = 35

    ax2.set_ylim(0, 0.5)
    ax1.set_ylim(0.5, 37)  

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