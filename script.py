import glob
import ipywidgets as ipw
import ipycanvas as ipc
from IPython.display import display
import os
import csv
import pandas as pd
from copy import deepcopy






class PathGuider:
    title = ipw.Label()
    canvas = ipc.Canvas(width=224, height=224)
    output = ipw.Output()

    def __init__(self, pattern, output_file):
        self.output_file = output_file
        open(output_file, 'w').close()  # clear contents
        self.images = glob.glob(pattern)
        self.iter_images = iter(self.images)
        self.canvas.line_width = 2
        self.canvas.stroke_style = 'red'
        self.canvas.on_mouse_move(self.handle_mouse_move)
        self.canvas.on_mouse_down(self.handle_mouse_down)

    def handle_mouse_move(self, x, y):
        if not self.last_path_image:
            return
        image = self.load_image(self.last_path_image)
        with ipc.hold_canvas():
            self.canvas.clear()
            self.canvas.draw_image(image)
            self.canvas.stroke_line(224//2, 224, x, y)

    def handle_mouse_down(self, x, y):
        if not self.last_path_image:
            return
        with open(self.output_file, 'a') as outf:
            filename_image = self.last_path_image.split('/')[-1]
            outf.write(f'xy_{x}_{y}_{filename_image}\n')
        self.next_image()

    def next_image(self):
        try:
            path_image = next(self.iter_images)
        except StopIteration:
            self.title.value = 'Finished.'
            self.canvas.clear()
            self.last_path_image = None
            return
        self.title.value = path_image.split('/')[-1]
        image = self.load_image(path_image)
        self.canvas.draw_image(image)
        self.last_path_image = path_image

    def load_image(self, path_image):
        with open(path_image, 'rb') as file:
            image = ipw.Image(value=file.read())
        return image

    def _ipython_display_(self):
        with self.output:
            display(self.title)
            display(self.canvas)
        display(self.output)
        self.next_image()

        
        
def renameImages(pathCSV, pathDataset):
    
    """
    pathCSV : на влез треба да добие CSV file што го добивте после PathGuider
    
    излез : добивате фолдер со обновени имиња на сите слики.
    """
    
    
    
    if pathCSV not in os.listdir():
        return "CSV фајлот не постои. Пробај повторно."
    
    df = pd.read_csv(pathCSV, header = None)
    df.rename(columns={0: "new_names"}, inplace=True)
    df["old_names"] = None
    df1 = deepcopy(df)
    for i, name in enumerate(df['new_names']):
        old_name = name.split('_')[3]
        df1.loc[i]['old_names'] = old_name
        
    # df.to_csv('data_jetbot_with_old.csv')
    # os.remove('data_jetbot.csv')
    # with open('data_jetbot_with_old.csv', mode='r') as f:
    #     reader = csv.DictReader(f)
    
    
    name_dict = {row['old_names']: row['new_names'] for _, row in df1.iterrows()}
    # name_dict = {row['old_names']: row['new_names'] for row in df}
    
    for filename in os.listdir(pathDataset):
        if filename in name_dict:
            os.rename(os.path.join(pathDataset, filename), os.path.join(pathDataset, name_dict[filename]))
    
    