import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

def plot_stacked_bar(data, series_labels, category_labels=None, 
                     show_values=False, value_format="{}", y_label=None, 
                     colors=None, grid=False, reverse=False, width=None):
    """Plots a stacked bar chart with the data and labels provided.

    Keyword arguments:
    data            -- 2-dimensional numpy array or nested list
                       containing data for each series in rows
    series_labels   -- list of series labels (these appear in
                       the legend)
    category_labels -- list of category labels (these appear
                       on the x-axis)
    show_values     -- If True then numeric value labels will 
                       be shown on each bar
    value_format    -- Format string for numeric value labels
                       (default is "{}")
    y_label         -- Label for y-axis (str)
    colors          -- List of color labels
    grid            -- If True display grid
    reverse         -- If True reverse the order that the
                       series are displayed (left-to-right
                       or right-to-left)
    """

    ny = len(data[0])
    ind = list(range(ny))

    axes = []
    cum_size = np.zeros(ny)

    data = np.array(data)

    if reverse:
        data = np.flip(data, axis=1)
        category_labels = reversed(category_labels)

    hatches = ['//', '\\\\', '--']
    handles = []
    for i, row_data in enumerate(data):
        color = colors[i] if colors is not None else None
        b = plt.bar(ind, row_data, bottom=cum_size, hatch=hatches[i],
                            label=series_labels[i], fill=False, color=None, edgecolor=color, width=width)
        axes.append(b)
        handles.append(b)
        cum_size += row_data

    if category_labels:
        plt.xticks(ind, category_labels)

    if y_label:
        plt.ylabel(y_label)

    plt.legend(handles=handles[::-1])

    if grid:
        plt.grid()

    if show_values:
        for axis in axes:
            for bar in axis:
                w, h = bar.get_width(), bar.get_height()
                plt.text(bar.get_x() + w/2, bar.get_y() + h/2, 
                         value_format.format(h), ha="center", 
                         va="center")

def main():
    series_labels = ['UE attach', 'User authentication', 'Load initial state']

    category_labels = ['Cloud', 'Without optimization', 'With optimization']

    data = [
        [1.403, 1.403, 1.403],
        [4.388, 2.124, 0.929],
        [5.423, 0.922, 0.661]
    ]

    mpl.rcParams.update({'font.size': 14})
    # plt.style.use('seaborn-talk')

    plot_stacked_bar(
        data, 
        series_labels, 
        category_labels=category_labels, 
        show_values=False, 
        value_format="{:.1f}",
        colors=['tab:blue', 'tab:orange', 'tab:green'],
        y_label="Latency (s)",
        width=0.3
    )

    plt.savefig('app_resumption_time.png')
    plt.savefig('app_resumption_time.svg')
    plt.show()

if __name__ == '__main__':
    main()
